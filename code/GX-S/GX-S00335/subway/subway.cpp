#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
    int v;
    ll w;
    bool operator < (const Node &y)const{
        return w>y.w;
    }
};
struct Query{
    int v,id;
};
const int N=5e5+5;
int c,n,m,d,Q;
ll w[N],ans[N];
vector<Node> e[N];
vector<Query> to[N];
priority_queue<Node> q;
void dijkstra(int rt){
    vector<bool> vis(5e5+5),f(5e5+5);
    vector<ll> dis(5e5+5,1e18);
    dis[rt]=0;
    for(int i=0;i<to[rt].size();i++) f[to[rt][i].v]=1;
    int cnt0=to[rt].size(),cnt=0;
    q.push({rt,0});
    while(q.size()){
        int u=q.top().v;
        ll sum=q.top().w;
        q.pop();
        if(vis[u]) continue;
        if(f[u]) cnt++;
        if(cnt==cnt0) break;
        for(int i=0;i<e[u].size();i++){
            int v=e[u][i].v;
            ll w1=e[u][i].w;
            if(dis[v]>w1+dis[u]){
                dis[v]=dis[u]+w1;
                q.push({v,dis[v]});
            }
        }
    }
    while(q.size()) q.pop();
    for(int i=0;i<to[rt].size();i++){
        ans[to[rt][i].id]=dis[to[rt][i].v]+w[rt]+w[to[rt][i].v];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
           int a,t;
           cin>>a>>t;
           e[a].push_back({i+m,t});
           e[i+m].push_back({a,t});
        }
    }
    for(int i=1;i<=Q;i++){
        int x,y;
        cin>>x>>y;
        to[x].push_back({y,i});
    }
    for(int i=1;i<=m;i++){
        if(to[i].size()){
            dijkstra(i);
        }
    }
    for(int i=1;i<=Q;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
