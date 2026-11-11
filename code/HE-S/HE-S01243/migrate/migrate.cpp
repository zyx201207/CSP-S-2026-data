#include <bits/stdc++.h>
#define up(i,l,r) for (int i = l, E##i = r; i <= E##i; ++i)
#define dn(i,l,r) for (int i = l, E##i = r; i >= E##i; --i)
using namespace std;
using L = long long;
constexpr L N = 2e6 + 5;
L c, t, n, d, x[N], l[N], r[N];
void solve1() {
  up (i, 1, n) l[i] = r[i] = 0;
  L y = 1, vl = 1, vr = 1;
  up (p, 1, n) {
    while (y < n && x[y + 1] - x[p] <= d) ++y;
    if (y <= p + 1) continue;
    vl = max(vl, y), vr = max(vr, y);
    while (vl < n && x[vl + 1] - x[y - 2] <= d) ++vl;
    while (vr < n && x[vr + 1] - x[y - 1] <= d) ++vr;
    l[p] = vl, r[p] = vr;
  }
  L ans = 0;
  up (v, 1, n) {
    L cnt = 0;
    dn (u, v - 1, 1) {
      if (x[u + 1] - x[u] > d) break;
      if (l[u] < v)
        cnt += min<L>(r[u], v) - l[u];
      if (cnt == 1) ++ans;
    }
  }
  cout << ans << '\n';
}
int main () {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> c >> t;
  while (t--) {
    cin >> n >> d;
    up (i, 1, n) cin >> x[i];
    up (i, 2, n) x[i] -= x[1];
    x[1] = 0;
    solve1();
  }
  return 0;
}
