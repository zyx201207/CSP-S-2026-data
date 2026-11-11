#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
const int N=5e5+5;
ll w[N];
ll f[505][505];
struct node{
    int v,w;
};
vector <node> G[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u,w;
            cin>>u>>w;
            G[u].push_back({i,w});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) f[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++){
        for(int u=0;u<G[i].size();u++){
            ll itv=G[i][u].v,itw=G[i][u].w;
            for(int v=0;v<G[i].size();v++){
                ll idv=G[i][v].v,idw=G[i][v].w;
                f[itv][idv]=min(f[itv][idv],itw+idw);
                f[idv][itv]=min(f[idv][itv],itw+idw);
            }
        }
    }
    for(int x=1;x<=n;x++){
        for(int i=1;i<=n;i++){
            if(i==x) continue;
            for(int j=i+1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][x]+f[x][j]);
            }
        }
    }
    while(q--){
        int u,v;
        ll ans=1e18;
        cin>>u>>v;
        for(int i=0;i<G[u].size();i++){
            ll itv=G[u][i].v,itw=G[u][i].w;
            for(int j=0;j<G[v].size();j++){
                ll idv=G[v][j].v,idw=G[v][j].w;
                ans=min(ans,min(f[itv][idv],f[idv][itv])+w[u]+w[v]+itw+idw);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
