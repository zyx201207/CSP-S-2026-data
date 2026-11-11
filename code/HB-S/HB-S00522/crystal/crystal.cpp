#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, a[500010], sum[500010], ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (ll i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);

    for (ll i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];

    for (ll i = 1; i <= n; ++i) {
        ll l = 1, r = i - 1;
        while (l < r) {
            ll mid = (l + r) >> 1;
            ll len = i - mid;
            if (a[i] * len - sum[i - 1] + sum[mid - 1] <= m) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }

    cout << ans;

    return 0;
}
