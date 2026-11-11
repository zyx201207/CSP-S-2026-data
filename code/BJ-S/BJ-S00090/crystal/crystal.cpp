#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500001],sum[500001];
bool check(ll mid){
    for(int i = mid;i<=n;i++){
        if((mid-1)*a[i]-(sum[i-1]-sum[i-mid]) <=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    ll l=1,r=n,ans=1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=max(ans,mid);
        }else{
            r=mid-1;
        }
    }
    cout << ans ;
    return 0;
}
