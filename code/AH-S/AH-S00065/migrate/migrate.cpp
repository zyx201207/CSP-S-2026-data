#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,T,t,n,d,a[2000005],le;
map<ll,ll> k;
void dfs(ll p,ll pp,ll co){
    if(co==le){
        if(p==pp) t++;
        return ;
    }
    for(ll i=1;i<=d;i++){
        if(k[p+i]!=0) dfs(p+i,pp,co+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ll s=0;
        scanf("%lld%lld",&n,&d);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            k[a[i]]++;
        }
        for(ll i=1;i<=n-3;i++){
            for(ll j=i+3;j<=n;j++){
                t=0;
                le=(a[j]-a[i]+1)/d+((a[j]-a[i]+1)%d==0?0:1);
                dfs(a[i],a[j],0);
                if(t==2) s++;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
