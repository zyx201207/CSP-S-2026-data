#include <bits/stdc++.h>
#define all(x) x.begin (), x.end ()
#define x first
using namespace std;
using ll = long long;
using db = double;

template <typename T>
inline void cmax (T &a, const T &b) {if (a < b) a = b;}
template <typename T>
inline void cmin (T &a, const T &b) {if (a > b) a = b;}

void init () {

}

void solve () {
    int n; ll m; cin >> n >> m;
    vector <ll> a (n + 1, 0ll);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a.begin () + 1, a.end ());

    int ans = 1;
    ll sum = 0;
    for (int p1 = 1, p2 = 2; p2 <= n; p2++) {
        sum += 1ll * (p2 - p1) * (a[p2] - a[p2 - 1]);
        while (p1 <= p2 && sum > m) sum -= a[p2] - a[p1], p1++;
        cmax (ans, p2 - p1 + 1);

        // cout << p1 << ' ' << p2 << '\n';
    }

    cout << ans << '\n';
}

int main () {
#ifndef ONLINE_JUDGE
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
#endif
    ios :: sync_with_stdio (0);
    cin.tie (0), cout.tie (0);

    init ();

    int t = 1;
    // cin >> t;
    while (t--) solve ();

    return 0;
}