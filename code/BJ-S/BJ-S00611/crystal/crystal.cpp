#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 90;
typedef long long ll;
ll n, m, f[N];
ll a[N], dp[101][101];
ll anser(ll x, ll a[]) {
    for (int i = 1; i <= n && m > 0; i++) {
        if (a[i] < x) {
            if (a[i] < 0 && x >= 0) {
                int ans = abs(a[i]) + x;
                a[i] += ans;
                m -= ans;
            } else if (a[i] < 0 && x < 0) {
                int ans = abs(a[i]) - abs(x);
                a[i] += ans;
                m -= ans;
            } else if (a[i] >= 0 && x >= 0) {
                int ans = x - a[i];
                a[i] += ans;
                m -= ans;
            }
        }
    }
    ll count = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == x) count++;
    }
    return count;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    ll maxn = -1e12;
    ll minn = 1e12;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(a[i], maxn);
        minn = min(a[i], minn);
    }
    sort(a + 1, a + n + 1);
    ll ans = -1e9;
    for (ll i = minn; i <= maxn; i++) ans = max(ans, anser(i, a));

    cout << ans;
    return 0;
}
