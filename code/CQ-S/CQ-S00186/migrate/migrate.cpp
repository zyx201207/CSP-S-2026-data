#include <bits/stdc++.h>
using ll = long long;
constexpr int N = 2e6 + 10;
int n; ll a[N], d;
int nxt[N], cntfr[N], cntto[N];
ll ans;
inline void slv(int L, int R) {
  std::fill(cntfr + L, cntfr + R + 1, 0);
  std::fill(cntto + L, cntto + R + 1, 0);
  for (int i = R - 1; i >= L; i--) {
    if (nxt[i - 1] < nxt[i]) {
      cntto[i] = cntto[nxt[i]] + nxt[i] - nxt[i - 1];
    }
  }
  for (int i = L; i < R; i++) {
    cntfr[i]++;
    int j = nxt[i];
    if (j >= i + 2) {
      int c = nxt[i - 1] >= j - 1 ? 1 : cntfr[i];
      ans += 1ll * c * (nxt[j - 1] - std::max(nxt[j - 2], j));
      if (nxt[j - 1] == nxt[j] && nxt[j - 2] < nxt[j])
        ans += 1ll * c * cntto[nxt[j]];
    }
    if (nxt[j - 1] < nxt[j])
      cntfr[j] += cntfr[i];
  }
}
inline void solve(int tt) {
  scanf("%d%lld", &n, &d);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &a[i]);
  ans = 0, nxt[n] = n;
  int r = n;
  for (int i = n - 1, j = n; i; i--) {
    while (a[j] - a[i] > d) j--;
    if ((nxt[i] = j) == i)
      slv(i + 1, r), r = i;
  }
  slv(1, r);
  printf("%lld\n", ans);
}
int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  int tn; scanf("%*d%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
    solve(tt);
  return 0;
}