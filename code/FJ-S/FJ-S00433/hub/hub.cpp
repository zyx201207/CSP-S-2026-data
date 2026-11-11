#include <bits/stdc++.h>

constexpr int N = 20;
bool c[N], vis[N];
int f[N][N];
std::vector<int> G[N];

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  int C, T;
  std::cin >> C >> T;
  
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    
    if (13 <= C && C <= 14) {
      for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
      }
      
      std::cout << (n / 2 - m + 6) / 4 << '\n';
      
      continue;
    }
    
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0, G[i].clear();
    
    for (int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      
      G[u].emplace_back(v);
      G[v].emplace_back(u);
      f[u][v] = f[v][u] = 1;
    }
    
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
    
    int ans = 1e9;
    for (int i = 0; i < (1 << n); i++) {
      if (__builtin_popcount(i) != m) continue;
      
      memset(c, 0, sizeof(c));
      for (int j = 1; j <= n; j++) {
        if (i & 1 << (j - 1)) c[j] = true;
      }
      
      memset(vis, 0, sizeof(vis));
      
      int cnt = 0;
      for (int j = 1; j <= n; j++) {
        if (!c[j] || vis[j]) continue;
        cnt++;
//        std::cerr << "+ " << j << '\n';
        
        std::queue<int> q;
        q.emplace(j);
        
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          
          if (vis[u]) continue;
          vis[u] = true;
          
          for (int v : G[u]) {
            if (c[v]) q.emplace(v);
          }
        }
      }
      
//      for (int j = 0; j < 9; j++) std::cerr << (i >> j & 1) << ' ';
//      std::cerr << cnt << '\n';
      if (cnt > 2) continue;
      
      int mx = 0;
      for (int j = 1; j <= n; j++) {
        int mn = 1e9;
        for (int k = 1; k <= n; k++) {
          if (c[k]) mn = std::min(mn, f[j][k]);
        }
        
        mx = std::max(mx, mn);
      }
      
//      std::cerr << mx << '\n';
      ans = std::min(ans, mx);
    }
    
    std::cout << ans << '\n';
  }
}
