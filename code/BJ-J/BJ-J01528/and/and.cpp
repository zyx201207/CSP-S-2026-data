#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 5;
bool a[N][40];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        for (ll j = 0; j <= 30; j++) {
            if (x & (1 << j)) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = 0;
            }
        }
    }
    ll ans = 0;
    for (ll i = 30; i >= 0; i--) {
        vector <ll> vec;
        ll num = 0;
        for (ll j = 1; j <= n; j++) {
            if (a[j][i] == 1) {
                num++;
            }
            else {
                vec.push_back(j);
            }
        }
        if (num >= m) {
            ans += (1 << i);
            for (auto j : vec) {
                for (ll k = 0; k <= 30; k++) {
                    a[j][k] = 0;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
