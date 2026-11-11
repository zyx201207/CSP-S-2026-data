#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e6 + 5;
int c, t, n, lst[N], nxt[N], f[N], g[N];
ll d, a[N];
vector<int> p[N], q[N];
int main() {
   freopen("migrate.in", "r", stdin);
   freopen("migrate.out", "w", stdout);
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> c >> t;
   while (t--) {
      cin >> n >> d;
      for (int i = 1; i <= n; i++) cin >> a[i];
      for (int i = 1; i <= n; i++) {
         lst[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
         nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
         if (i ^ nxt[i]) p[nxt[i]].push_back(i);
         if (i ^ lst[i]) q[lst[i]].push_back(i);
      }
      for (int i = 1; i <= n; i++)
         if (p[i].empty()) f[i] = 1;
         else f[i] = f[p[i].front()] + p[i].size();
      for (int i = n; i; i--)
         if (q[i].empty()) g[i] = 1;
         else g[i] = g[q[i].back()] + q[i].size();
      ll ans = 0;
      for (int i = 1; i < n; i++) {
         int x = f[i + 1] - 1, y = g[i] - 1;
         if (p[i + 1].size() && p[i + 1].front() == i) x = p[i + 1].size() - 1;
         if (q[i].size() && q[i].back() == i + 1) y = q[i].size() - 1;
         if (p[i + 1].size() && nxt[p[i + 1].front() - 1] == i) x = min(x, (int)p[i + 1].size());
         if (q[i].size() && lst[q[i].back() + 1] == i + 1) y = min(y, (int)q[i].size());
         if (x > 0 && y > 0) ans += 1ll * x * y;
      }
      cout << ans << "\n";
      for (int i = 1; i <= n; i++) nxt[i] = lst[i] = f[i] = g[i] = 0, p[i].clear(), q[i].clear();
   }
   return 0;
}