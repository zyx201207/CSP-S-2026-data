#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
ll ans = 1;
ll a[500005], sum[500005];

int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    ll l = 1;
    for (int i = 1; i <= n; ++i) {
        while (1ll * (ll)(i - l + 1) * a[i] - (sum[i] - sum[l - 1]) > m && l < i) {
            l++;
        }
        if (1ll * (ll)(i - l + 1) * a[i] - (sum[i] - sum[l - 1]) <= m) {
            ans = max(ans, i - l + 1);
        }
    }
    cout << ans;
    return 0;
}
