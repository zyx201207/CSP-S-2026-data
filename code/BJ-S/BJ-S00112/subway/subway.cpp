#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=505,M=5e5+5,Q=1e5+5;
int c,n,m,p,q;
int w[M],ans[Q],fa[N+M];
int f[N+M][21],dis[N+M],dep[N+M];
int Find(int x){
    if(x==fa[x])return x;
    else return fa[x]=Find(fa[x]);
}
bool Merge(int x,int y){
    if(Find(x)==Find(y))return 0;
    else fa[x]=fa[y];
    return 1;
}
struct check{
    int id,s,t;
}ask[Q];
struct edge{
    int to,val;
};
struct Edge{
    int u,v,w;
};
vector<edge> mp[N+M];
vector<Edge> edges;
void dfs(int now,int father){
    dep[now]=dep[father]+1;
    f[now][0]=father;
    for(int i=1;i<=20;i++)f[now][i]=f[f[now][i-1]][i-1];
    for(edge e:mp[now]){
        int p=e.to,w=e.val;
        if(p==father)continue;
        dis[p]=dis[now]+w;
        dfs(p,now);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=0;i<=20;i++){
        if(d&(1<<i))u=f[u][i];
    }
    if(u==v)return u;
    for(int i=20;i>=0;i--)if(f[u][i]!=f[v][i]){
        u=f[u][i];
        v=f[v][i];
    }
    return f[u][0];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>p>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            edges.push_back({i,n+a,t});
        }
    }
    for(int i=1;i<=n+m;i++)fa[i]=i;
    sort(edges.begin(),edges.end(),[](Edge a,Edge b){return a.w<b.w;});
    int cnt=0;
    for(Edge e:edges){
        int u=e.u,v=e.v,w=e.w;
        if(Merge(u,v)){
            cnt++;
            mp[u].push_back({v,w});
            mp[v].push_back({u,w});
        }
        if(cnt==n+m-1)break;
    }
    dfs(1,0);
    for(int i=1;i<=q;i++){
        int s,t;
        cin>>s>>t;
        int l=lca(s+n,t+n);
        cout<<dis[s+n]+dis[t+n]-2*dis[l]+w[s]+w[t]<<'\n';
    }
    return 0;
}
