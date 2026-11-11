#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qt;
int a[200005];
int b[505][1005],t[505][505];
int dis[505],vis[505];
queue<int> q;
struct node{
    int to,w;
};
vector<node> g[505];
void SPFA(int u){
    dis[u]=0;
    vis[u]=1;
    q.push(u);
    while(q.size()){
        int t=q.front();
        q.pop();
        vis[t]=0;
        for(int i=0;i<g[t].size();i++){
            int v=g[t][i].to;
            if(vis[v]==1) continue;
            if(dis[v]>dis[t]+g[t][i].w){
                dis[v]=dis[t]+g[t][i].w;
                vis[v]=1;
                q.push(v);
            }
        }
    }
    return ;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>qt;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>b[i][j]>>t[i][j];
        }
        g[b[i][1]].push_back({b[i][2],t[i][2]+t[i][1]});
        g[b[i][2]].push_back({b[i][1],t[i][1]+t[i][2]});
    }
    while(qt--){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        while(q.size()) q.pop();
        int u,v;
        cin>>u>>v;
        int ans=0;
        ans+=a[u];
        ans+=a[v];
        SPFA(u);
        ans+=dis[v];
        cout<<ans<<'\n';
    }
    return 0;
}
