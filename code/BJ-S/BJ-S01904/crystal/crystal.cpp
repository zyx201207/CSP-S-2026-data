#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],sum[500005],n,m;
bool c(int md){
    for(int l=md;l<=n;l++){
        if((md-1)*a[l]-sum[l-1]+sum[l-md]<=m) return 1;
    }
    return 0;
}
signed main()
{
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
    int l=1,r=n,ans=1;
    while(l<=r){
        int md=l+((r-l)>>1);
        if(c(md)){
            l=md+1;
            ans=md;
        }
        else{
            r=md-1;
        }
    }
    cout<<ans;
}
