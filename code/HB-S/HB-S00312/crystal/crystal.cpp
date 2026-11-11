#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n + 5, 0);
    for (ll i = 1; i <= n; i++)
        cin >> p[i];
    sort(p.begin() + 1, p.begin() + 1 + n);
    ll ans = 1, cnt = 0;
    ll l = 1, r = 1;
    while (l <= r && r <= n) {
        r ++;
        cnt += (r - l) * (p[r] - p[r - 1]);
        while (cnt > m) {
            cnt -= p[r] - p[l];
            l ++;
        }
        ans = max(ans, r - l + 1);
    } 
    cout << ans << '\n';
    return 0;
}