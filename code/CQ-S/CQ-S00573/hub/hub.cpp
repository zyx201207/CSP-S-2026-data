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
    int n, k; cin >> n >> k;
    cout << ((n / 2) + 2 - k) / 3 << '\n';
}

int main () {
#ifndef ONLINE_JUDGE
    freopen ("hub.in", "r", stdin);
    freopen ("hub.out", "w", stdout);
#endif
    ios :: sync_with_stdio (0);
    cin.tie (0), cout.tie (0);

    init ();

    int t = 1, c;
    cin >> c >> t;
    while (t--) solve ();

    return 0;
}