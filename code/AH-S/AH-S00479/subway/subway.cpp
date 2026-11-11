#include<bits/stdc++.h>
using namespace std;
#define N 50005
#define ll long long
ll n,m,d,q,c;
int cnt;
struct node{
    int next,w;
};
vector<node> g[2*N+505];
struct edge{
    int id,d;
    bool operator <(const edge &b)const{
        return d>b.d;
    }
};
long long dis[2*N+505];
bool vis[2*N+505];
void dijkstra(int st){
    for(int i=1;i<=2*m+n;i++)
            dis[i]=1e18;
    priority_queue<edge> q;
    dis[st]=0;
    memset(vis,0,sizeof(vis));
    q.push({st,0});
    while(!q.empty()){
        edge h=q.top();q.pop();
        int u=h.id;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].next;
            if(dis[v]>dis[u]+g[u][i].w){
                dis[v]=dis[u]+g[u][i].w;
                q.push({v,dis[v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1,w;i<=m;i++){
        cin>>w;
        g[i].push_back({i+m,w});
        g[i+m].push_back({i,w});
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,u,t;j<=k;j++){
            cin>>u>>t;
            g[u+m].push_back({i+2*m,t});
            g[i+2*m].push_back({u+m,t});
        }
    }
    for(int i=1;i<=q;i++){
            int st,ed;
        cin>>st>>ed;
        dijkstra(st);
        cout<<dis[ed]<<'\n';
    }
    return 0;
}
