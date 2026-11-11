#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
const int INF=1e18;
int c,n,m,d,Q,w[maxn];
vector<int>dis[505];
bool vis[maxn];
struct Edge{
    int v,w;
};
bool operator < (Edge a,Edge b){
    return a.w>b.w;
}
priority_queue<Edge>q;
vector<Edge>G[maxn<<1];
void dijkstra(int id){
    for(int i=1;i<=m+n;i++)dis[id-m][i]=INF,vis[i]=0;
    dis[id-m][id]=0;
    q.push({id,0});
    while(!q.empty()){
        int u=q.top().v;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(Edge e:G[u]){
            int v=e.v,w=e.w;
            if(dis[id-m][v]>dis[id-m][u]+w){
                dis[id-m][v]=dis[id-m][u]+w;
                if(!vis[v])q.push({v,dis[id-m][v]});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
    	for(int j=0;j<=n+m+1;j++)dis[i].push_back(0);
	}
    for(int i=1,len;i<=n;i++){
        cin>>len;
        for(int j=1,v,w;j<=len;j++){
            cin>>v>>w;
            G[i+m].push_back({v,w});
            G[v].push_back({i+m,w});
        }
    }
    for(int i=1;i<=n;i++)dijkstra(i+m);
    for(int i=1,u,v;i<=Q;i++){
        cin>>u>>v;
        int ans=INF;
        for(Edge e:G[u])ans=min(ans,dis[e.v-m][u]+dis[e.v-m][v]);
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}
/**/
