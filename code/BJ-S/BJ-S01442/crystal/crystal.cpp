#include <bits/stdc++.h>
#define int long long
using namespace std;
int n = 0;
int m = 0 ;
int a[500010];
int sum[500010];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r",stdin);
    freopen("crystal.out", "w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){ cin >> a[i]; }
    sort(a + 1, a + 1 + n);
    int ans = 1;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i]; //cout << a[i] << " " <<sum[i] << '\n';
        int k = 0; int l = 1; int r = i;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(mid * a[i] - sum[i] + sum[i - mid] <= m){
                k=mid;l = mid+1;
            } else r = mid -1;
        } ans = max(ans, k);
    } cout << ans << '\n';
}
