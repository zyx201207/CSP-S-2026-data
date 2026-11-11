#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 10;
ll n, m, a[N];
bool f(ll x) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= x) {
            sum += x - a[i];
        }
    }
    return (sum <= m);
}
void solve() {
    cin >> n >> m;
    ll l = 1e12, r = -1e12;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    r *= 2;
    sort(a + 1, a + 1 + n);
    ll ans = 0, md;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (f(mid)) {
            l = mid + 1;
            md = mid;
        } else {
            r = mid - 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] <= md) {
            ans++;
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
