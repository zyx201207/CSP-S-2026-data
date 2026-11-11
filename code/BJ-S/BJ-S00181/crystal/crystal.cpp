#include <bits/stdc++.h>
using namespace std;
long long a[500001];
long long sum[500001];
long long n,m;
bool check(long long x,long long y){
    long long s = (y-x)*a[y]-(sum[y-1]-sum[x-1]);
    return s<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long ans = 0;
    cin>>n>>m;
    for(int f = 1; f<=n; f++) cin>>a[f];
    sort(a+1,a+n+1);
    for(int f = 1; f<=n; f++) sum[f] = sum[f-1]+a[f];
    for(int f = 1; f<=n; f++){
        int l = 0,r = f-1;
        long long res = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(check(mid,f)){
                r = mid-1;
                res = max(res,1LL*(f-mid+1));
            }
            else {
                l = mid+1;
            }
        }
        ans = max(ans,res);
    }
    cout<<ans;
    return 0;
}
