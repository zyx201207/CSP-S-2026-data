#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio (0), cin.tie (0), cout.tie (0)
#define res register int
#define rep(i, l, r) for (res i = (l); i <= (r); ++ i)
#define drep(i, l, r) for (res i = (r); i >= (l); -- i)
#define tim clock () * 1.0 / CLOCKS_PER_SEC
#define iv inline void
#define pb push_back
#define mst(x, y) memset (x, y, sizeof x)
using namespace std;
using ll = long long; using vi = vector <int>;
bool _BG;
const int N = 1e6 + 5;
namespace _ {
    template <typename T> iv cmin (T &x, T y) { x = x < y ? x : y; }
    template <typename T> iv cmax (T &x, T y) { x = x > y ? x : y; }
}
using namespace _;
int sub, n, m, a[N], ans, d[N], b[N];
vi G[N];
iv clr () { rep (i, 1, n) G[i].clear (); }
void get (int u) { for (auto v : G[u]) if (b[v]) b[v] = 0, get (v); }
iv calc () {
    queue <int> Q;
    rep (i, 1, n) d[i] = n, b[i] = a[i];
    rep (i, 1, n) if (b[i]) Q.push (i), d[i] = 0;
    int t = 0;
    rep (i, 1, n) if (b[i]) ++ t, get (i);
    if (t > 2) return;
    while (! Q.empty ()) {
        int u = Q.front (); Q.pop ();
        for (auto v : G[u]) if (d[v] > d[u] + 1) d[v] = d[u] + 1, Q.push (v);
    }
    int mx = 0;
    rep (i, 1, n) cmax (mx, d[i]);
    cmin (ans, mx);
}
void dfs (int x, int y) {
    if (y > m) return;
    if (y + n - x + 1 < m) return;
    if (x > n) return calc ();
    a[x] = 1; dfs (x + 1, y + 1);
    a[x] = 0; dfs (x + 1, y);
}
int U, V, dm, fa[N], h[N], tot;
void qry (int u, int o, int ft = 0, int d = 0) {
    if (d > dm) dm = d, (o ? V : U) = u; fa[u] = ft;
    for (auto v : G[u]) if (v ^ ft) qry (v, o, u, d + 1);
}
mt19937 rnd (91);
iv solve () {
    clr ();
    cin >> n >> m;
    rep (i, 2, n) { int u, v; cin >> u >> v; G[u].pb (v), G[v].pb (u); }
    if (m == n) return cout << "0\n", void ();
    ans = n;
    if (n <= 20) {
        dfs (1, 0);
        return cout << ans << '\n', void ();
    }
    if (sub == 13 || sub == 14) {
        if (m >= n / 2) return cout << "1\n", void ();
        rep (i, m / 2, m / 2 + 1) rep (j, m / 2, m / 2 + 1) if (i + j == m) {
            int t = ((n + 1) / 2 - m) / 4;
            rep (I, t - 2, t + 2) {
                rep (J, t - 2, t + 2) {
                    rep (o, 1, n) a[o] = 0;
                    rep (o, I, I + i - 1) a[o] = 1;
                    rep (o, (n + 1) / 2 - J - j + 1, (n + 1) / 2 - J) a[o] = 1;
                    int s = 0;
                    rep (o, 1, n) s += a[o];
                    if (s == m) calc ();
                }
            }
        }
        return cout << ans << '\n', void ();
    }
    U = V = dm = 0;
    qry (1, 0);
    dm = 0;
    qry (U, 1);
    tot = 0;
    while (V ^ U) h[++ tot] = V, V = fa[V]; h[++ tot] = U;
    if (tot < m) {
        rep (i, 1, n) a[i] = 0, b[i] = i;
        rep (i, 1, tot) a[h[i]] = 1;
        calc ();
        return cout << ans << '\n', void ();
    }
    rep (i, m / 2, m / 2 + 1) rep (j, m / 2, m / 2 + 1) if (i + j == m) {
        int t = (tot - m) / 4;
        rep (I, t - 2, t + 2) {
            rep (J, t - 2, t + 2) {
                rep (o, 1, n) a[o] = 0;
                rep (o, I, I + i - 1) a[h[o]] = 1;
                rep (o, tot - J - j + 1, tot - J) a[h[o]] = 1;
                int s = 0;
                rep (o, 1, n) s += a[o];
                if (s == m) calc ();
            }
        }
    }
    cout << ans << '\n';
}
bool _ED;
signed main () {
    freopen ("hub.in", "r", stdin);
    freopen ("hub.out", "w", stdout);
    IOS;
    int T; cin >> sub >> T;
    while (T --) solve ();
    cerr << "\nT: " << tim << "s\n";
    cerr << "M: " << (&_BG - &_ED) / 1024.0 / 1024 << "MB\n";
    return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/