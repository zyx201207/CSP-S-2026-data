#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n , m , a[N] , sum[N] , ans;
bool check(int l , int r){
    return a[r] * (r - l + 1) - (sum[r] - sum[l-1]) <= m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int l = 1 , r = i , nw = i;
        sum[i] = sum[i-1] + a[i];
        while(l<=r){
            int mid = (l + r) >> 1;
            if(check(mid,i))nw = mid , r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans,i-nw+1);
    }
    cout << ans;
    return 0;
}