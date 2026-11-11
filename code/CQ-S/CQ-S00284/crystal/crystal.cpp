#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    vector<ll>a(n + 1, 0);
    vector<ll>sum(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (ll i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ll l = 1, r = i;
        auto check = [&](ll mid) {
            return a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) <= m; // too kR
        };
        ll res = i;
        while (l <= r) {
            ll mid = (l + r) / 2;
            // cerr << l << " " << r << endl;
            if (check(mid)) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        // cerr << res - i + 1 << endl;
        ans = max(ans, i - res + 1);
        // cerr << endl;
    }
    cout << ans << endl;
}