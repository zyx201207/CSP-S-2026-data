#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define U(i,a,b) for(int i = (a); i < (b); i++)
#define drep(i,a,b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define ld lower_bound
#define pii pair<ll,ll>
#define vi vector<ll>
#define fi first
#define se second
#define fv inline void
#define fn inline static
#define mem(s,x) memset(s, x, sizeof(s))
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using i32 = ll; using i64 = ll; using u32 = unsigned int; using u64 = unsigned long long;
const i32 mod = 998244353, inf = 1e18;
fv inc(i32 &x, i32 y) { x = (x + y >= mod ? x + y - mod : x + y); }
fv dec(i32 &x, i32 y) { x = (x - y < 0 ? x - y + mod : x - y); }
fn i32 madd(i32 x, i32 y) { return (x + y >= mod ? x + y - mod : x + y); }
fn i32 msub(i32 x, i32 y) { return (x - y < 0 ? x - y + mod : x - y); }
const i32 N = 5e5 + 5;
i32 c, m, n, d, q, w[N], f[505][505];
vector <pii> S[N], P[N];
int main() {
  IOS;
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin >> c >> m >> n >> d >> q;
  rep (i, 1, n) cin >> w[i];
  rep (i, 1, m) {
    i32 k; cin >> k;
    rep (j, 1, k) {
      i32 x, y; cin >> x >> y;
      S[i].pb({x, y}), P[x].pb({i, y});
    }
  }
  mem(f, 0x3f);
  rep (i, 1, n) {
    for (auto [j, wj] : P[i]) {
      for (auto [k, wk] : P[i]) {
        f[j][k] = min(f[j][k], wj + wk);
        f[k][j] = min(f[k][j], wj + wk);
      }
    }
  }
  rep (i, 1, m) f[i][i] = 0;
  rep (k, 1, m) rep (i, 1, m) rep (j, 1, m) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  rep (i, 1, q) {
    i32 x, y, ans = inf;
    cin >> x >> y;
    for (auto [x, wx] : P[x]) for (auto [y, wy] : P[y]) {
      ans = min(ans, wx + wy + f[x][y]);
    }
    cout << ans + w[x] + w[y] << "\n";
  }
}