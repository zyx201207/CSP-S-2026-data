#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio (0), cin.tie (0), cout.tie (0)
#define res register int
#define rep(i, l, r) for (res i = (l); i <= (r); ++ i)
#define drep(i, l, r) for (res i = (r); i >= (l); -- i)
#define tim clock () * 1.0 / CLOCKS_PER_SEC
#define iv inline void
#define pb push_back
using namespace std;
using ll = long long;
bool _BG;
const int N = 5e5 + 5;
namespace _ {
    template <typename T> iv cmin (T &x, T y) { x = x < y ? x : y; }
    template <typename T> iv cmax (T &x, T y) { x = x > y ? x : y; }
}
using namespace _;
int n, ans;
ll m, a[N], s[N];
iv solve () {
    cin >> n >> m;
    rep (i, 1, n) cin >> a[i];
    sort (a + 1, a + n + 1);
    rep (i, 1, n) s[i] = s[i - 1] + a[i];
    res j = 1;
    rep (i, 1, n) {
        while (s[i] - s[j - 1] + m < a[i] * (i - j + 1)) ++ j;
        cmax (ans, i - j + 1);
    }
    cout << ans << '\n';
}
bool _ED;
signed main () {
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    IOS;
    int T = 1; //cin >> T;
    while (T --) solve ();
    cerr << "\nT: " << tim << "s\n";
    cerr << "M: " << (&_BG - &_ED) / 1024.0 / 1024 << "MB\n";
    return 0;
}
/*
5 5
1 2 4 8 9

*/