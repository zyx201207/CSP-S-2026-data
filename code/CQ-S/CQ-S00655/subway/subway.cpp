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
const int N = 5e5 + 5, M = 5e2 + 5; const ll inf = 2e18;
namespace _ {
    template <typename T> iv cmin (T &x, T y) { x = x < y ? x : y; }
    template <typename T> iv cmax (T &x, T y) { x = x > y ? x : y; }
}
using namespace _;
int sub, n, m, d, q;
ll a[N], f[M][M];
vector <array <ll, 2> > g[N];
iv solve () {
    cin >> sub >> m >> n >> d >> q;
    rep (i, 1, n) cin >> a[i];
    mst (f, 0x3f);
    rep (i, 1, m) {
        int x, y, z; cin >> x; f[i][i] = 0;
        rep (j, 1, x) cin >> y >> z, g[y].pb ({i, z});
    }
    rep (i, 1, n) for (auto e1 : g[i]) for (auto e2 : g[i]) if (e1[0] ^ e2[0]) cmin (f[e1[0]][e2[0]], e1[1] + e2[1]);
    rep (k, 1, m) rep (i, 1, m) rep (j, 1, m) cmin (f[i][j], f[i][k] + f[k][j]);
    rep (i, 1, q) {
        int x, y; cin >> x >> y; ll t = inf;
        for (auto e1 : g[x]) for (auto e2 : g[y]) cmin (t, f[e1[0]][e2[0]] + e1[1] + e2[1] + a[x] + a[y]);
        cout << t << '\n';
    }
}
bool _ED;
signed main () {
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    IOS;
    int T = 1; //cin >> T;
    while (T --) solve ();
    cerr << "\nT: " << tim << "s\n";
    cerr << "M: " << (&_BG - &_ED) / 1024.0 / 1024 << "MB\n";
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/