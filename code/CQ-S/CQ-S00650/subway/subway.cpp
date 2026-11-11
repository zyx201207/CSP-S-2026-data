#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,M=1e6+10;
int n,m,q,w[N],cnt,idx,fa[M];
struct node{
    int u,v,val;
    bool operator < (const node &p){
        return val<p.val;
    }
}e[M];
vector<pii>g[M];
inline int Find(int x){return (fa[x]==x)?x:(fa[x]=Find(fa[x]));}
ll dis[M];
int dep[M],f[M][25];
inline void dfs(int u,int p){
    dep[u]=dep[p]+1;
    f[u][0]=p;
    for(int i=1;i<=20;i++)f[u][i]=f[f[u][i-1]][i-1];
    for(auto k:g[u]){
        int v=k.first,vl=k.second;
        if(v==p)continue;
        dis[v]=dis[u]+vl;
        dfs(v,u);
    }
}
inline int Lca(int u,int v){
    if(dep[u]>dep[v])swap(u,v);
    for(int i=20;i>=0;i--){
        if(dep[u]<=dep[v]-(1<<i))v=f[v][i];
    }
    if(u==v)return v;
    for(int i=20;i>=0;i--){
        if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
    }
    return f[u][0];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,d;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    idx=m;
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a,t;j<=k;j++){
            cin>>a>>t;
            e[++cnt]={a,++idx,t};
        }
        for(int j=1;j<k;j++)e[++cnt]={idx-k+j,idx-k+j+1,0};
    }
    sort(e+1,e+1+cnt);
    for(int i=1;i<=idx;i++)fa[i]=i;
    for(int i=1;i<=cnt;i++){
        int u=Find(e[i].u),v=Find(e[i].v);
        if(u==v)continue;
        fa[u]=v;
        g[e[i].u].push_back({e[i].v,e[i].val});
        g[e[i].v].push_back({e[i].u,e[i].val});
    }
    dfs(1,1);
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dis[x]+dis[y]-2LL*dis[Lca(x,y)]+w[x]+w[y]<<"\n";
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

