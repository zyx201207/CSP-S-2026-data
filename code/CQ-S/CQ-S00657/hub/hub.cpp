/*
有点空悲切了，没写完 T4 2log。
T3 调了 1h，难道我真的是弱智。 
希望 T4 的暴力不要挂分吧，唉唉，这个大样例也太水了。
希望今年能去个 WC 玩玩，NOIP 再加油吧。 
by 770611.
四了。 
*/
#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define U(i,a,b) for(int i = (a); i < (b); i++)
#define drep(i,a,b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define ld lower_bound
#define pii pair<ll,ll>
#define vi vector<int>
#define fi first
#define se second
#define fv inline void
#define fn inline static
#define mem(s,x) memset(s, x, sizeof(s))
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using i32 = int; using i64 = ll; using u32 = unsigned int; using u64 = unsigned long long;
const i32 mod = 998244353, inf = 1e9;
fv inc(i32 &x, i32 y) { x = (x + y >= mod ? x + y - mod : x + y); }
fv dec(i32 &x, i32 y) { x = (x - y < 0 ? x - y + mod : x - y); }
fn i32 madd(i32 x, i32 y) { return (x + y >= mod ? x + y - mod : x + y); }
fn i32 msub(i32 x, i32 y) { return (x - y < 0 ? x - y + mod : x - y); }
namespace BF {
  const i32 N = 4e3 + 5;
  i32 n, k, u, v, fa[N], diam[N], diam2[N];
  vi G[N];
  fv dfs0(i32 u, i32 f) {
    fa[u] = f;
    for (i32 v : G[u]) {
      if (v == f) continue ;
      dfs0(v, u);
    }
  }
  i32 banu, banv, rt, p, q, dis[N];
  fn bool check(i32 u, i32 v) {
    if (u == banu && v == banv) return 1;
    if (v == banu && u == banv) return 1;
    return 0;
  }
  fv dfs1(i32 u, i32 _fa) {
    dis[u] = dis[_fa] + 1;
    if (dis[u] > dis[rt]) rt = u;
    for (i32 v : G[u]) {
      if (v == _fa || check(u, v)) continue ;
      dfs1(v, u);
    }
  }
  vi S;
  fn bool get(i32 u, i32 _fa, i32 to) {
    if (u == to) return S.pb(u), 1;
    for (i32 v : G[u]) {
      if (v == _fa || check(u, v)) continue ;
      if (get(v, u, to)) return S.pb(u), 1;
    }
    return 0;
  }
  i32 mxdep[N][N];
  fv dfs2(i32 u, i32 _fa, i32 id) {
    mxdep[id][u] = 0;
    for (i32 v : G[u]) {
      if (v == _fa || check(u, v)) continue ;
      dfs2(v, u, id);
      mxdep[id][u] = max(mxdep[id][u], mxdep[id][v] + 1);
    }
  }
  fn bool check(i32 mid) {
    rep (i, 1, n) {
      i32 cnt = 1 + (i > 1);
      rep (j, 1, n) cnt += (mxdep[i][j] >= mid);
      if (cnt <= k) return 1;
    }
    return 0;
  }
  fv sol() {
    cin >> n >> k;
    rep (i, 1, n) fa[i] = 0;
    rep (i, 1, n) G[i].clear();
    S.clear(), rt = p = q = 0;
    U (i, 1, n) cin >> u >> v, G[u].pb(v), G[v].pb(u);
    if (n == k) return cout << "0\n", void();
    dfs0(1, 0);
    rep (i, 1, n) diam[i] = diam2[i] = 0;
    rep (i, 1, n) {
      banu = i, banv = fa[i];
      rt = 0, dfs1(i, 0), p = rt, rt = 0, dfs1(p, 0), q = rt;
      S.clear(), get(p, 0, q);
      diam[i] = S[(i32)S.size() >> 1], dfs2(diam[i], 0, i);
      mxdep[i][diam[i]] = 0;

      if (fa[i]) {
        rt = 0, dfs1(fa[i], 0), p = rt, rt = 0, dfs1(p, 0), q = rt;
        S.clear(), get(p, 0, q);
        diam2[i] = S[(i32)S.size() >> 1], dfs2(diam2[i], 0, i);
        mxdep[i][diam2[i]] = 0;
      }
      
    }
    // cerr << diam[1] << " - " << diam2[1] << "\n";
    i32 l = 0, r = n, ans = n;
    while (l <= r) {
      i32 mid = (l + r) >> 1;
      if (check(mid)) ans = mid, r = mid - 1;
      else l = mid + 1;
    }
    cout << ans << "\n";
  }
} ;
namespace TASK11 {
  const i32 N = 1e6 + 5;
  i32 n, k, u, v, f[2][N], g[2][N];
  vi E[N];
  fv dfs0(i32 u, i32 fa) {
    f[0][u] = g[0][u] = f[1][u] = g[1][u] = 0;
    for (i32 v : E[u]) {
      if (v == fa) continue ;
      dfs0(v, u);
      f[0][u] = max({f[0][u], f[0][v], g[0][u] + g[0][v] + 1});
      g[0][u] = max(g[0][u], g[0][v] + 1);
    }
    // cerr << u << " : " << f[0][u] << " - " << g[0][u] << "\n";
  }
  fv dfs1(i32 u, i32 fa, i32 F, i32 G) {
    multiset <i32> Sg, Sf;
    Sg.insert(G + 1), Sf.insert(F), Sg.insert(0), Sf.insert(0);
    for (i32 v : E[u]) {
      if (v == fa) continue ;
      Sg.insert(g[0][v] + 1), Sf.insert(f[0][v]);
    }
    f[1][u] = F;
    for (i32 v : E[u]) {
      if (v == fa) continue ;
      Sg.erase(Sg.find(g[0][v] + 1)), Sf.erase(Sf.find(f[0][v]));
      i32 res = F;
      res = max(res, *prev(Sf.end()));
      res = max(res, *prev(Sg.end()) + *prev(prev(Sg.end())));
      dfs1(v, u, res, *prev(Sg.end()));
      Sg.insert(g[0][v] + 1), Sf.insert(f[0][v]);
    }
  }
  fv sol() {
    cin >> n >> k;
    rep (i, 1, n) E[i].clear();
    U (i, 1, n) cin >> u >> v, E[u].pb(v), E[v].pb(u);
    dfs0(1, 0);
    if (k == 1) return cout << (f[0][1] + 1) / 2 << "\n", void();
    dfs1(1, 0, 0, -1);
    i32 ans = inf;
    rep (i, 1, n) ans = min(ans, max(f[0][i], f[1][i]));
    if (n == k) ans = 0;
    cout << (ans + 1) / 2 << "\n";
  }
}
namespace Fun {
  const i32 N = 1e6 + 5;
  i32 n, k, u, v, f[2][N], g[2][N];
  vi E[N];
  fv dfs0(i32 u, i32 fa) {
    f[0][u] = g[0][u] = f[1][u] = g[1][u] = 0;
    for (i32 v : E[u]) {
      if (v == fa) continue ;
      dfs0(v, u);
      f[0][u] = max({f[0][u], f[0][v], g[0][u] + g[0][v] + 1});
      g[0][u] = max(g[0][u], g[0][v] + 1);
    }
    // cerr << u << " : " << f[0][u] << " - " << g[0][u] << "\n";
  }
  fv sol() {
    cin >> n >> k;
    rep (i, 1, n) E[i].clear();
    U (i, 1, n) cin >> u >> v, E[u].pb(v), E[v].pb(u);
    dfs0(1, 0);
    if (k > 1) {
      i32 d = (n - 1) / 2;
      i32 dmid = (d + 1) / 2 - (k & 1);
      cout << (dmid - k / 2 + 1) / 2 + 1 << "\n";
    } else {
      return cout << (f[0][1] + 1) / 2 << "\n", void();
    }
    
  }
}
int main() {
  IOS;
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  i32 c, T; cin >> c >> T;
  if (c <= 10) {
    rep (i, 1, T) BF::sol();
    return 0;
  } else if (11 <= c && c <= 12) {
    rep (i, 1, T) TASK11::sol();
    return 0;
  } else if (13 <= c && c <= 14) {
    rep (i, 1, T) Fun::sol();
    return 0;
  }
}
