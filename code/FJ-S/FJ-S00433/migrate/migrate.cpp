#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e6 + 10, N2 = 1e3 + 10;
int n, mn, cnt;
i64 d, x[N];

void dfs(int i, int s, int e) {
//  std::cerr << i << ' ' << s << ' ' << e << '\n';
  if (i == e) {
//    std::cerr << s << '\n';
    if (s < mn) mn = s, cnt = 1;
    else if (s == mn) cnt++;
    
    return;
  }
  
  for (int j = i + 1; j <= n; j++) {
    if (x[j] - x[i] > d) break;
    dfs(j, s + 1, e);
  }
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  int C, T;
  std::cin >> C >> T;
  
  while (T--) {
    std::cin >> n >> d;
    for (int i = 1; i <= n; i++) std::cin >> x[i];
    
    if (n <= 3) {
      std::cout << 0 << '\n';
      continue;
    }
    
    if (11 <= C && C <= 12) {
      i64 dif = x[2] - x[1];
      if (d < 2 * dif) std::cout << 0 << '\n';
      else std::cout << std::max(0LL, n - d / dif * 2 + 1) << '\n';
      continue;
    }
    
    if (13 <= C && C <= 14) {
      
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 3; j <= n; j++) {
//        std::cerr << i << ' ' << j << '\n';
        mn = 1e9, cnt = 0;
        dfs(i, 0, j);
        if (cnt == 2) ans++;
      }
    
    std::cout << ans << '\n';
  }
}
