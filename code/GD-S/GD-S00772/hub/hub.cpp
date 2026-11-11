#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define pii pair <int, int>
#define chkmx(a, b) (a = max(a, (b)))
#define chkmn(a, b) (a = min(a, (b)))
using namespace std;
const int N = 2e6 + 5, K = 21;
int type, n, k, st[K][N], dfn[N], ar, par[N], dep[N];
vector <int> edge[N];
int low(int a, int b){
  return dfn[a] < dfn[b] ? a : b;
}
void dfs(int p, int fa){
  par[p] = fa;
  dfn[p] = ++ ar;
  st[0][ar] = fa;
  for (auto to : edge[p]) if (to != fa){
    dep[to] = dep[p] + 1;
    dfs(to, p);
  }
}
int LCA(int u, int v){
  if (u == v) return u;
  u = dfn[u], v = dfn[v];
  if (u > v) swap(u, v);
  int lg = __lg(v - u);
  return low(st[lg][u + 1], st[lg][v - (1 << lg) + 1]);
}
int dis(int u, int v){
  // cerr << u + 1 << ' ' << v + 1 << ' ' << dep[u] + dep[v] - 2 * dep[LCA(u, v)] << endl;
  return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
}
void solve(){
  cin >> n >> k;
  ar = 0;
  for (int i = 0; i <= n; i ++) edge[i].clear();
  for (int i = 1; i < n; i ++){
    int u, v; cin >> u >> v, u --, v --;
    edge[u].pb(v), edge[v].pb(u);
  }
  dfs(0, 0);
  for (int k = 1; k < K; k ++){
    for (int i = 1; i + (1 << k) - 1 <= n; i ++) st[k][i] = low(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
  }
  if (type <= 3){
    int ans = 1e9, anss = -1;
    for (int s = 1; s < (1 << n); s ++) if (__builtin_popcount(s) == k){
      vector <int> imp, isimp(n);
      for (int t = s; t; t -= t & -t) imp.pb(__builtin_ctz(t)), isimp[__builtin_ctz(t)] = 1;
      queue <int> q;
      vector <int> vis(n);
      int cnt = 0;
      for (auto st : imp) if (!vis[st]){
        cnt ++;
        q.push(st), vis[st] = 1;
        while (!q.empty()){
          int p = q.front(); q.pop();
          for (auto to : edge[p]) if (isimp[to] && !vis[to]) vis[to] = 1, q.push(to);
        }
      }
      if (cnt > 2) continue;
      int mx = 0;
      for (int i = 0; i < n; i ++){
        int mn = 1e9;
        for (auto to : imp) chkmn(mn, dis(i, to));
        chkmx(mx, mn);
      }
      // cerr << s << ' ' << mx << endl;
      // chkmn(ans, mx);
      if (mx < ans) ans = mx, anss = s;
    }
    cout << ans << '\n';
    return;
  }
  if (type == 7){
    int ans = 1e9;
    for (int a = 0; a < n; a ++) for (int b = a + 1; b < n; b ++){
      int mx = 0;
      for (int i = 0; i < n; i ++) chkmx(mx, min(dis(a, i), dis(b, i)));
      chkmn(ans, mx);
    }
    cout << ans << '\n';
    return;
  }
}
signed main(){
  cin.tie(0)->sync_with_stdio(0);
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  int _ = 1; cin >> type >> _;
  while (_ --) solve();
  return 0;
}