#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN = 5e5 + 5;
ll n, k;
ll a[MAXN];
ll s[MAXN];
bool chk(ll x) {
    for(int i = x; i <= n; i++) {
        if(a[i] * x - s[i] + s[i - x] <= k)
            return 1;
    }
    return 0;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    ll l = 1, r = n, ans = 1;
    while(l <= r) {
        ll mid = l + r >> 1;
        if(chk(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}