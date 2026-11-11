#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 5;
ll a[N], qz[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll l = 1, ans = 0, num = 0;
    for (ll i = 1; i <= n; i++) {
        if (i != 1) {
            while ((num + m) / (i - l) < a[i]) {
                num -= a[l];
                l++;
            }
        }
        num += a[i];
        ans = max(ans, i - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
