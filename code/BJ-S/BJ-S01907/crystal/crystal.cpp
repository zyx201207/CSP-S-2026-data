#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005], s[500005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (ll i = 2; i <= n; i++) {
        s[i] = s[i - 1] + (a[i] - a[i - 1]) * (i - 1) * 1LL;
    }
    ll l = 1, r = 1;
    ll ans = 1;
    while (r < n) {
        while (s[r + 1] - s[l - 1] - (l - 1) * (a[r + 1] - a[l - 1]) <= m && r < n) r++;
        ans = max(ans, r - l + 1);
        l++;
        if (r == n) break;
    }
    cout << ans;
    return 0;
}
