#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int M=5e5+10;
int c,n,m,d,q,idx;
int w[M];
struct Edges
{
    int u,v,w;
};
vector <Edges> edges;
vector <PII> e[M*2];
bool cmp(Edges x,Edges y)
{
    return x.w<y.w;
}
int mfa[M*2];
int getf(int x)
{
    if(x==mfa[x]) return x;
    else return mfa[x]=getf(mfa[x]);
}
int hs[M*2],sz[M*2],dep[M*2],tp[M*2],fa[M*2];
void dfs_hs(int x,int f)
{
    dep[x]=dep[f]+1;
    fa[x]=f;
    sz[x]=1;
    for(auto it:e[x]){
        if(it.first==f) continue;
        dfs_hs(it.first,x);
        sz[x]+=sz[it.first];
        if(sz[it.first]>sz[hs[x]]) hs[x]=it.first;
    }
}
void dfs_tp(int x,int top)
{
    tp[x]=top;
    if(hs[x]) dfs_tp(hs[x],top);
    for(auto it:e[x]){
        if(it.first==fa[x]||it.first==hs[x]) continue;
        dfs_tp(it.first,it.first);
    }
}
int lca(int x,int y)
{
    while(tp[x]!=tp[y]){
        if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
        x=fa[tp[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    return x;
}
int dis[M*2];
void dfs_dis(int x,int dist)
{
    dis[x]=dist;
    for(auto it:e[x]){
        if(it.first==fa[x]) continue;
        dfs_dis(it.first,dist+it.second);
    }
}
void pre_solve()
{
    for(int i=1;i<=idx;i++) mfa[i]=i;
    sort(edges.begin(),edges.end(),cmp);
    for(auto it:edges){
        int u=it.u,v=it.v,w=it.w;
        if(getf(u)==getf(v)) continue;
        mfa[getf(u)]=getf(v);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs_hs(1,0);
    dfs_tp(1,1);
    dfs_dis(1,0);
}
int get_dis(int x,int y)
{
    return dis[x]+dis[y]-2*dis[lca(x,y)];
}
void solve()
{
    int x,y; cin>>x>>y;
    cout<<w[x]+w[y]+get_dis(x,y)<<'\n';
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    idx=m;
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        for(int j=1;j<=k;j++){
            int a,t; cin>>a>>t;
            idx++;
            if(j!=1) edges.push_back({idx,idx-1,0});
            edges.push_back({idx,a,t});
        }
    }
    pre_solve();
    while(q--) solve();
    return 0;
}