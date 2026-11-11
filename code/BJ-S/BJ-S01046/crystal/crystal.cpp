#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans;
ll m,a[500005],sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    ll l=1,r=1;
    for(r=1;r<=n&&l<=r;r++){
        ll cnt=a[r]*(r-l+1);
        ll nw=sum[r]-sum[l]+a[l];
        if(cnt-nw<=m){
            ans=max(ans,r-l+1);
        }else{
            ll tx=nw;
            while(cnt-tx>m){
                if(l>r)break;
                cnt-=a[r];
                tx-=a[l];
                l++;
            }
            if(cnt-tx<=m)ans=max(ans,r-l+1);
        }
        //cout<<l<<' '<<r<<' '<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
