#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e5 + 10;
i64 a[N], sum[N];

signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  int n;
  i64 m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  
  std::sort(a + 1, a + n + 1);  
  std::partial_sum(a + 1, a + n + 1, sum + 1);
  
  int ans = 0;
  i64 k = 0;
  for (int i = 1, j = 1; i <= n; i++) {
    k += (i - j) * (a[i] - a[i - 1]);
    while (k > m) k -= a[i] - a[j++];
    ans = std::max(ans, i - j + 1);
  }
  
  std::cout << ans << '\n';
}
