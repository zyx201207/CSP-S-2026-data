#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll energy[500050],sum[500050];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m,ans=0;cin>>n>>m;
    for(ll i=1;i<=n;++i)cin>>energy[i];
    sort(energy+1,energy+n+1);
    for(ll i=1;i<=n;++i)sum[i]=sum[i-1]+energy[i];
    for(ll i=n;i>0;--i){
        if(ans>=i)break;
        for(ll j=0;j<=i;++j){
            if(m>=((i-j)*energy[i]-sum[i]+sum[j])){
                ans=max(i-j,ans);break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
