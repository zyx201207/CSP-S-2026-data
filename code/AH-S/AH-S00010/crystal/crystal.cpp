#include <bits/stdc++.h>
#define ll long long
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
ll n, m, a[500005], f[500005];
int ans;
int main() {
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    faster;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++ i) f[i] = f[i-1] + a[i];
    for (int i = 1; i <= n; ++ i) {
        int l = 1, r = i, res  = i;
        while (l <= r) {
            int mid = l+r >> 1;
            ll len = i-mid+1;
            ll cost = len * a[i] - (f[i] - f[mid-1]);
            if (cost <= m) res = mid, r = mid-1;
            else l = mid+1;
        }
        ans = max(ans, i-res+1);
    }
    cout << ans;
    return 0;
}//zap
