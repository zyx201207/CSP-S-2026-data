#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e2+10;
int c,T,n,k;
vector <int> e[N];
int ans;
bool used[N];
int hs[N],sz[N],dep[N],tp[N],fa[N];
void dfs_hs(int x,int f)
{
    dep[x]=dep[f]+1;
    fa[x]=f;
    sz[x]=1;
    for(auto it:e[x]){
        if(it==f) continue;
        dfs_hs(it,x);
        sz[x]+=sz[it];
        if(sz[it]>sz[hs[x]]) hs[x]=it;
    }
}
void dfs_tp(int x,int top)
{
    tp[x]=top;
    if(hs[x]) dfs_tp(hs[x],top);
    for(auto it:e[x]){
        if(it==fa[x]||it==hs[x]) continue;
        dfs_tp(it,it);
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
int getdis(int x,int y)
{
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void dfs(int x,int cur)
{
    if(used[x]) return;
    if(cur==0)
    used[x]=1;
    for(auto it:e[x]){
        dfs(it,cur-1);

    }
}

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ans=0x3f3f3f3f3f3f3f3f;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v; cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs_hs(1,0);
        dfs_tp(1,1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                memset(used,0,sizeof used);
                for(int s=0;s<=k;s++){
                    dfs(i,s);
                    dfs(j,k-s);
                }
            }
        }
    }
    return 0;
}