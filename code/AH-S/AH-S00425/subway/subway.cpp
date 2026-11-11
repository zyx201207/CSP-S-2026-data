#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll xl,ti;
};
vector<node> g[500010];
ll a[510][510],vis[500010],w[500010],y,minn=0x3f3f3f3f,hc[500010];
void dfs(ll u,ll time,ll now){
    if(time>minn) return;
    if(u==y){
        minn=min(minn,time);
        return;
    }
    vis[u]=1;
    for(ll i=0;i<g[u].size();i++){
        ll xl=g[u][i].xl;
        for(ll j=1;j<=a[xl][i];j++){
            if(!vis[a[xl][j]] && xl==now){
                dfs(a[xl][j],time,now);
            }
        }
    }
    for(ll i=0;i<g[u].size();i++){
        ll xl=g[u][i].xl,ti=g[u][i].ti;
        if(xl!=now && !hc[u]){
            hc[u]=1;
            for(ll j=0;j<g[u+1].size();j++){
                if(g[u+1][j].xl==xl) dfs(u,time+ti+g[u][j].ti,xl);
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll i=1,k;i<=n;i++){
        cin>>k;
        a[i][0]=k;
        for(ll j=1,ai,ti;j<=k;j++){
            cin>>a[i][j]>>ti;
            g[a[i][j]].push_back({i,ti});
        }
    }
    while(q--){
        ll x;
        cin>>x>>y;
        for(ll i=0;i<g[x].size();i++) dfs(x,w[x]+w[y]+g[x][i].ti+g[y][i].ti,g[x][i].xl);
        cout<<minn<<endl;
        minn=0x3f3f3f3f;
        memset(vis,0,sizeof(vis));
        memset(hc,0,sizeof(hc));
    }
    return 0;
}
