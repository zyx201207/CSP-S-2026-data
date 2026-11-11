#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,q,C,w[1000001],a[1000001],t[1000001],vis[1000001],dis[1000001],ans[3001][3001],aa[601][25001];
struct node{
    int u,d;
};
bool operator<(node x,node y){
    return x.d>y.d;
}
vector<node>g[1000001];
void dij(int u){
    priority_queue<node>q;
    for(int i=1;i<=m;i++)vis[i]=0,dis[i]=1e18;
    dis[u]=0,q.push({u,0});
    while(q.size()){
        node u=q.top();
        q.pop();
        if(!vis[u.u]){
            vis[u.u]=1;
            for(int i=0;i<g[u.u].size();i++){
                int v=g[u.u][i].u,d=g[u.u][i].d;
                if(dis[v]>u.d+d)dis[v]=u.d+d,q.push({v,dis[v]});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,x;i<=n;i++){
        cin>>x;
        for(int j=1;j<=x;j++)cin>>a[j]>>t[j];
        for(int j=1;j<=x;j++)for(int k=j+1;k<=x;k++)
        g[a[j]].push_back({a[k],t[j]+t[k]}),g[a[k]].push_back({a[j],t[j]+t[k]});
    }
    if(C>=9&&C<=11){
        for(int i=1;i<=m;i++){
            dij(i);
            for(int j=1;j<=m;j++)ans[i][j]=dis[j];
        }
        while(q--){
            int u,v;
            cin>>u>>v;
            cout<<w[u]+w[v]+ans[u][v]<<"\n";
        }
        return 0;
    }
    else{
        while(q--){
            int u,v;
            cin>>u>>v;
            dij(u);
            cout<<w[u]+w[v]+dis[v]<<"\n";
        }
    }
    return 0;
}
