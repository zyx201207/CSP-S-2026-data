#include<bits/stdc++.h>//T2
#define int long long
using namespace std;
const int N=2e3+13;
int c,n,m,d,q,w[N],dis[N][N],ds[200013],vis[200013];
vector<pair<int,int>>g[200013];
void dijkstra(int st){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    q.push({0,st});
    fill(dis[st]+1,dis[st]+n+m+1,1e9+13);
    dis[st][st]=0;
    while(!q.empty()){
        auto [d,u]=q.top();
        q.pop();
        if(dis[st][u]<d)continue;
        for(auto [v,w]:g[u]){
            if(dis[st][v]>d+w){
                dis[st][v]=d+w;
                q.push({d+w,v});
            }
        }
    }
}
void bfs(int st){
    fill(ds+1,ds+1+m+n,1e9+13);
    memset(vis,0,sizeof(vis));
    queue<int>p;
    p.push(st);
    ds[st]=0;
    vis[st]=1;
    while(!p.empty()){
        int u=p.front();
        p.pop();
        for(auto[v,w]:g[u]){
            if(vis[v])continue;
            ds[v]=ds[u]+w;
            p.push(v);
            vis[v]=1;
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            g[i+m].push_back({a,t});
            g[a].push_back({i+m,t});
        }
    }
    if(c>=12&&c<=15){
        while(q--){
            int x,y;
            cin>>x>>y;
            bfs(x);
            cout<<w[x]+w[y]+ds[y]<<'\n';
        }
        return 0;
    }
    for(int i=1;i<=m;i++){
        dijkstra(i);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+dis[x][y]<<'\n';
    }
    return 0;
}
