#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
ll n, m, sum[N], a[N];
bool check(ll x) {
    for(int i = 1; i <= n - x + 1; i++) {
        ll ri = i + x - 1;
        ll mi = (i + ri) >> 1;
        ll an = 0;
        an += a[mi] * (mi - i) - sum[mi - 1] + sum[i - 1];
        an += sum[ri] - sum[mi] - a[mi] * (ri - mi);
        if(an <= m) {
            return true;
        }
    }
    return false;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    ll l = 1, r = n, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(check(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
