#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 10;

ll n, a[N], m;

void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (m == 1) {
        ll mx = 0;
        for (int i = 1; i <= n; i++)
                mx = max (mx, a[i]);
        cout << mx << '\n';
    } else if (m == n) {
        ll ans = a[1];
        for (int i = 2; i <= n; i++)
            ans = (ans & a[i]);
        cout << ans << '\n';
    } else if (m == 2) {
        ll ans = 0;
        for (int i = 1; i <= n - 1; i++)
            for (int j = i + 1; j <= n; j++)
                ans = max (ans, (a[i] & a[j]));
        cout << ans << '\n';
    } else {
        cout << 0;
    }
}

int main () {
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);

    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);

    int T = 1; // cin >> T;
    while (T--) {
        solve ();
    }

    return 0;
}
