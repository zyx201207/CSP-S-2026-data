#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10;
int n, m, a[maxn], sum[maxn];
int query(int l, int r) {
    return a[r]*(r-l)-(sum[r-1]-sum[l-1]);
}
int solve(int i) {
    int l = 1, r = i, res = i;
    while(l <= r) {
        int mid = (l+r)>>1;
        if(query(mid,i) <= m) {
            res = mid;
            r = mid-1;
        } else l = mid+1;
    }
    return res;
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, i-solve(i)+1);
    }
    cout << ans << "\n";
    return 0;
}