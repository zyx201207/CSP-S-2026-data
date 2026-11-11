#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[500005], pre[500005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll ma = 0;
    for (ll i = 1; i <= n; ++i) {
        ll l = 1, r = i - 1, ans = 0;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (m >= (i - mid) * a[i] - (pre[i-1] - pre[mid-1])) {
                ans = i - mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        ma = max(ma, ans + 1);
        pre[i] = pre[i-1] + a[i];
        
    }
    cout << ma << endl;
    return 0;
}