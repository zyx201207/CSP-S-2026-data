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
const int N = 2e6 + 5;
namespace _ {
    template <typename T> iv cmin (T &x, T y) { x = x < y ? x : y; }
    template <typename T> iv cmax (T &x, T y) { x = x > y ? x : y; }
}
using namespace _;
int n, f[N], g[N], s1[N], s2[N], t1[N], t2[N], h1[N], h2[N];
ll m, a[N], ans;
iv clr () { ans = 0; rep (i, 0, n) s1[i] = s2[i] = t1[i] = t2[i] = h1[i] = h2[i] = 0; }
iv solve () {
    clr ();
    cin >> n >> m;
    rep (i, 1, n) cin >> a[i];
    rep (i, 1, n) {
        f[i] = f[i - 1];
        while (f[i] < n && a[f[i] + 1] - a[i] <= m) ++ f[i];
        ++ s1[f[i]];
    }
    g[n + 1] = n + 1;
    drep (i, 1, n) {
        g[i] = g[i + 1];
        while (g[i] > 1 && a[i] - a[g[i] - 1] <= m) -- g[i];
        ++ s2[g[i]];
    }
    rep (i, 0, n - 1) {
        t1[i + 1] = s1[i + 1];
        h1[i + 1] = s1[i + 1];
        if (f[g[i + 1]] == i + 1) t1[i + 1] += t1[g[i + 1]];
        if (f[g[i + 1]] == i + 1 && g[i] == g[i + 1]) h1[i + 1] += t1[g[i + 1]];
    }
    drep (i, 1, n) {
        t2[i] = s2[i];
        h2[i] = s2[i];
        if (g[f[i]] == i) t2[i] += t2[f[i]];
        if (g[f[i]] == i && f[i] == f[i + 1]) h2[i] += t2[f[i]];
    }
    rep (i, 2, n - 2) if (f[i] > i + 1 && g[i + 1] < i) ans += (ll) h1[i + 1] * h2[i];
    // rep (i, 2, n - 2) if (f[i] > i + 1 && g[i + 1] < i) {
    //     int t1 = 0, t2 = 0;
    //     int t = i + 1;
    //     // cout << i << '\n';
    //     while (t) {
    //         rep (j, 1, t - 1) if (f[j] == t) ++ t1;
    //         if (f[g[t]] == t && g[i] == g[i + 1]) t = g[t];
    //         else break;
    //     }
    //     // cout << '\n';
    //     t = i;
    //     while (t) {
    //         rep (j, t + 1, n) if (g[j] == t) ++ t2;
    //         if (g[f[t]] == t && f[i] == f[i + 1]) t = f[t];
    //         else break;
    //     }
    //     // cout << '\n';
    //     // cout << '\n';
    //     ans += (ll) t1 * t2;
    // }
    cout << ans << '\n';
}
bool _ED;
signed main () {
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    IOS;
    int T; cin >> T >> T;
    while (T --) solve ();
    cerr << "\nT: " << tim << "s\n";
    cerr << "M: " << (&_BG - &_ED) / 1024.0 / 1024 << "MB\n";
    return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/