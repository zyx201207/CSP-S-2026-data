#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 5;
int c, t, n, k, h[N];
vector<int> e[N];
inline void dfs1(int u, int fa) {
   for (auto v : e[u]) {
      if (v == fa) continue;
      dfs1(v, u);
      if (h[u]) h[u] = min(h[u], h[v] + 1);
      else h[u] = h[v] + 1;
   }
}
inline void dfs2(int u, int fa) {
   for (auto v : e[u]) {
      if (v == fa) continue;
      h[v] = min(h[v], h[u] + 1), dfs2(v, u);
   }
}
inline bool check(int d) {
   int rt = 0;
   for (int i = 1; i <= n; i++)
      if (h[i] == d)
         rt = i;
   if (!rt) return 1;
   int ans = 0;
   function<int(int, int)> get = [&](int u, int fa) {
      int res = 0;
      vector<int> p;
      for (auto v : e[u]) {
         if (v == fa) continue;
         int x = get(v, u) + 1;
         if (x) p.push_back(x);
      }
      if (p.empty()) return h[u] ^ d ? -1 : 0;
      sort(p.begin(), p.end());
      if (fa || p.size() ^ 2) ans = max(ans, p.back() - 1);
      else ans = max(ans, p[0] + p[1] - 1);
      if (h[u] == d) return 0;
      else return p.size() > 1 ? -1 : p[0];
   };
   get(rt, 0), ans = min(ans, d * 2);
   for (int i = 1; i <= n; i++)
      if (h[i] < d)
         ans++;
   return ans + k >= n;
}
int main() {
   freopen("hub.in", "r", stdin);
   freopen("hub.out", "w", stdout);
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> c >> t;
   while (t--) {
      cin >> n >> k;
      for (int i = 1, u, v; i < n; i++) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
      dfs1(1, 0);
      if (e[1].size() == 1) h[1] = 0;
      dfs2(1, 0);
      int l = 0, r = n;
      while (l < r) {
         int mid = l + r >> 1;
         if (check(mid)) r = mid;
         else l = mid + 1;
      }
      cout << l << "\n";
      for (int i = 1; i <= n; i++) h[i] = 0, e[i].clear();
   }
   return 0;
}