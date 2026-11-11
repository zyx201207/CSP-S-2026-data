#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 5;
ll a[N], la[N], ra[N];
char c[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ll n;
    cin >> n;
    ll m = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        la[i] = ra[i - 1] + 1;
        ra[i] = ra[i - 1] + a[i];
        m += a[i];
    }
    ll l = 1, r = n, ll1 = 1, lr = ra[1], rl = la[n], rr = m, ans = 0;
    while (l < r) {
        ll1 = la[l];
        lr = ra[l];
        rl = la[r];
        rr = ra[r];
        if (c[l] != c[r]) {
            ans += min(lr, m - rl + 1) - max(ll1, m - rr + 1) + 1;
        }
        if (lr > m - rl + 1) {
            r--;
        }
        else {
            l++;
        }
    }
    cout << ans << '\n';
    return 0;
}
