#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e5 + 5;
ll a[N], sum[N];
ll n, m;

bool check(ll x) {
    for (ll i = 1; i <= n - x + 1; i++) {
        ll j = i + x - 1;
        if (a[j] * x - (sum[j] - sum[i - 1]) <= m) return 1;
    }
    return 0;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (ll i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    ll l = 1, r = n, ans;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}