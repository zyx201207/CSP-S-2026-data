#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 5e5 + 10;

ll n, m, a[N];

pair<ll, ll> f (ll x) {
    ll res = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= x) {
            res += (x - a[i]);
            cnt++;
        } else if (a[i] > x) {
            break;
        }
    }
    return {cnt, res};
}

void solve () {
    cin >> n >> m;
    ll mx = LLONG_MIN, mn = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max (mx, a[i]);
        mn = min (mn, a[i]);
    }

    sort (a + 1, a + 1 + n);
    ll l = mn, r = m, ans = 0;
    while (l < r) {
        ll mid = ((l + r) >> 1);
        if (f (mid).second <= m) {
            l = mid + 1;
            ans = max (ans, f (mid).first);
        } else {
            r = mid;
        }
    }
    cout << ans << '\n';
}

int main () {
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);

    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);

    int T = 1; // cin >> T;
    while (T--) {
        solve ();
    }

    return 0;
}
