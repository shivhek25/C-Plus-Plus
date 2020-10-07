public int numIslands(char[][] grid) {
        
        if (grid == null || grid.length == 0)
            return 0;
        
        int m = grid.length, n = grid[0].length;
        int total = 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, m, n, i, j);
                    total++;
                }                    
            }
        }
        
        return total;        
    }
    
    private void dfs(char[][] grid, int m, int n, int i, int j) {
        if (i<0 || j<0 || i>=m || j>=n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        int[][] dirs = new int[][]{{1,0},{0,1}, {-1,0}, {0,-1}};
        for (int[] dir: dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            dfs(grid, m, n, x, y);
        }
    }
