#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[2000200];
ll a[2000200];
bool slv[2000200];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;cin>>c>>t;
    for(ll i=0;i<t;++i){
        ll n,d,ans=0;cin>>n>>d;
        for(ll i=1;i<=n;++i)cin>>x[i];
        for(ll i=1;i<=n;++i){
            while(i+a[i]<=n && x[i+a[i]]-x[i]<=d)++a[i];
            --a[i];
        }
        for(ll i=n-2;i>0;--i){
            if(a[i]>1){
                int s=0;
                for(ll j=i+1;j<=i+a[i];++j)if(a[j]>0)++s;
                ans+=slv[i]=(s==2);
            }else if(a[i]==1)ans+=slv[i];
        }
        cout<<ans<<endl;
        memset(a+1,0,4*n);
        memset(a+1,0,n);
    }
    return 0;
}
