#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll idx, T;
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> idx >> T;
    for(ll t = 1; t <= T; t ++) {
        ll n, d, ans = 0;
        cin >> n >> d;
        vector<ll> p(n + 5, 0);
        for(ll i = 1; i <= n; i ++) cin >> p[i];
        for(ll i = 1; i + 3 <= n; i ++) {
            if(p[i + 1] <= p[i] + d && p[i + 2] <= p[i] + d && p[i + 1] + d <= p[i + 3]) {
                for(ll j = i;p[j] >= 1; j -- ) {
                    if(p[j] + d < p[i]) break;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}