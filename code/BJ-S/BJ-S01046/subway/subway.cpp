#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c,m,n,d,q;
ll ans;
ll w[500005],k[505],f[600005];
struct edge{
    ll v;
    ll w;
};
vector<edge>e[600005];
void dfs(ll u,ll fini,ll dep){
    if(dep>=ans)return;
    if(u==fini){
        ans=min(ans,dep);
    }
    for(auto i:e[u]){
        if(f[i.v]==0){
            f[i.v]=1;
            dfs(i.v,fini,dep+i.w);
            f[i.v]=0;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        ll id=m+i;
        for(int j=1;j<=k[i];j++){
            ll a,t;
            cin>>a>>t;
            e[id].push_back({a,t});
            e[a].push_back({id,t});
        }
    }
    while(q--){
        memset(f,0,sizeof(f));
        ans=1e18;
        ll x,y;
        cin>>x>>y;
        f[x]=1;
        dfs(x,y,0);
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
