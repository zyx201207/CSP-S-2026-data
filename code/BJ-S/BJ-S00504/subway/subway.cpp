#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pi;
const ll N=5e5+10;
const ll inf=1e18;
ll c,n,m,d,q,w[N],dis[N];
int s,t;
struct edge{
    int v;
    ll w;
};
vector<edge> g[N];
priority_queue<pi,vector<pi>,greater<pi>> pq;
bool vis[N];
void dijkstra(){
    for(int i=1;i<=n+m;i++) dis[i]=inf;
    for(int i=1;i<=n+m;i++) vis[i]=0;
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        pi tmp=pq.top(); pq.pop();
        int u=tmp.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].v,w=g[u][i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];

    for(int i=1;i<=n;i++){
        int k; cin>>k;
        for(int j=1;j<=k;j++){
            int a; ll t;
            cin>>a>>t;
            g[m+i].push_back({a,t});
            g[a].push_back({m+i,t});
        }
    }

    while(q--){
        cin>>s>>t;
        dijkstra();
        ll ans=dis[t]+w[s]+w[t];
        cout<<ans<<'\n';
    }

    return 0;
}

