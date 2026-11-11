#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5;
ll n, m, a[N], ans;
ll check(ll x) {
    ans = 0;
    ll sum = 0;
    ll pos = -1;
    for (ll i = 0; i < n; i++) if (a[i] <= x) pos++;
    //if (x != a[pos]) pos--;
    //cout << pos << " ";
    ll t = a[pos];
    //cout << x << " " << pos << "\n";
    for (ll i = pos; i >= 0; i--) {
        //cout <<a[i] << " ";
        sum += (x - a[i]);
        if (sum > m) return sum;
        ans++;
    }
    return sum;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    ll minN = LLONG_MAX, maxN = LLONG_MIN;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        maxN = max(maxN, a[i]);
        minN = min(minN, a[i]);
    }
    sort(a, a + n);
    //for (ll i = 1; i <= n; i++) cout <<a[i] << " ";
    ll l = minN, r = maxN, mid = 0, res = 0;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        ll num = check(mid);
        //cout << num << " ";
        //cout <<ans << " ";
        if (num > m) r = mid - 1;
        else l = mid + 1;
        res = max(ans, res);

    }
    cout << res;
    return 0;
}
