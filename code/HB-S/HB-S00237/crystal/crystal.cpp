#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m;
int a[N];
int sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int res = 1;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++)sum[i] = sum[i-1]+a[i];
    for(int i = 1;i<=n;i++){
        int l = 0,r = i,ans = 0;
        while(l<=r){
            int mid = (l+r)>>1;
            if((i-mid)*a[i]-(sum[i]-sum[mid])<=m)ans = mid,r = mid-1;
            else l = mid+1;
        } 
        res = max(res,i-ans);
    }
    cout<<res;
    return 0;
}