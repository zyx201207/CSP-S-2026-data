#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N],dis[N*2];
struct bian{int v,w;};
bool vis[N*2];
vector <bian> e[N*2];
void addedge(int x,int y,int z){
    e[x].push_back({y,z});
    e[y].push_back({x,z});
}
void dijkstra(int s){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    dis[s]=0;q.push({0,s});
    while (!q.empty()){
        int now=q.top().second;
        q.pop();
        if (vis[now]) continue;
        vis[now]=1;
        for (auto o:e[now]){
            int v=o.v,w=o.w;
            if (dis[now]+o.w<dis[v]){
                dis[v]=dis[now]+o.w;
                q.push({dis[v],v});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];

    for (int i=1;i<=n;i++){
        int a,k,t;
        cin>>k;
        for (int j=1;j<=k;j++){
            cin>>a>>t;
            addedge(a,i+m,t);
        }
    }
    while (q--){
        int x,y;
        cin>>x>>y;
        dijkstra(x);
        cout<<dis[y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
