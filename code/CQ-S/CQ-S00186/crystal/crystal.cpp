#include <bits/stdc++.h>
using ll = long long;
constexpr int N = 5e5 + 10;
int n; ll m, a[N];
int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  scanf("%d%lld", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &a[i]);
  std::sort(a + 1, a + n + 1);
  ll sum = 0; int ans = 0;
  for (int r = 1, l = 1; r <= n; r++) {
    sum += 1ll * (r - l) * (a[r] - a[r - 1]);
    while (sum > m)
      sum -= a[r] - a[l++];
    ans = std::max(ans, r - l + 1);
  }
  printf("%d\n", ans);
  return 0;
}