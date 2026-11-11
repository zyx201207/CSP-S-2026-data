#include <bits/stdc++.h>

constexpr int N = 2e5 + 10;
int a[N], cnt[30];

int main() {
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
  
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  
  for (int i = 29; i >= 0; i--) {
    for (int j = 1; j <= n; j++) {
      if (a[j] & 1 << i) cnt[i]++;
    }
    
    if (cnt[i] >= m) {
      for (int j = 1; j <= n; j++) a[j] &= (1 << (i + 1)) - 1;
      break;
    }
  }
  
  std::sort(a + 1, a + n + 1, std::greater<int>());
  
  int ans = (1 << 30) - 1;
  for (int i = 1; i <= m; i++) ans &= a[i];
  
  std::cout << ans << '\n';
}
