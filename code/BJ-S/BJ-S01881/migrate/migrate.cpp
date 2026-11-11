#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e6 + 10;
ll x[N];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ll c, t;
    cin >> c >> t;
    while (t--) {
        ll n, d;
        cin >> n >> d;
        for (ll i = 1; i <= n; ++i) {
            cin >> x[i];
        }
        ll gc = x[2] - x[1];
        ll Log = d / gc + 1;
        ll Max = x[n] - x[1];
        ll ans = (Max % Log == 0LL) ? (Max / Log) : (Max / Log + 1ll);
        cout << ans << '\n';
    }
    return 0;
}