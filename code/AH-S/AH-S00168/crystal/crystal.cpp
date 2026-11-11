#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],f[500005],p,s=1,l=1,r,ans;
bool ff(ll mid){
    ll s=0;
    for(ll i=mid,x;i<=n;i++){
        x=(mid-1)*a[i]-(f[i]-f[r-mid+1]);
        if(x<=mid){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    r=n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    f[0]=0;
    for(ll i=1;i<=n;i++){
        f[i]=f[i-1]+a[i];
    }
    ll mid;
    while(true){
        if(!(l<=r)){
            break;
        }
        mid=(l+r)/2;
        if(ff(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
