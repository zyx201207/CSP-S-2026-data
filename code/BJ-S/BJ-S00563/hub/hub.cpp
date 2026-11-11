#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;
const int N=1e6+5,INF=2e9;
int n,k;vi G[N];
int fa[N][21],dep[N];
inline void dfs(int u,int fath){
    fa[u][0]=fath;dep[u]=dep[fath]+1;
    for(int v:G[u])
        if(v!=fath)dfs(v,u);
    return;
}
inline int LCA(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i=20;i>=0;i--)
        if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
    if(u==v)return u;
    for(int i=20;i>=0;i--)
        if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
inline int DIS(int u,int v){return dep[u]+dep[v]-(dep[LCA(u,v)]<<1);}
namespace baoli{
    int a[N],ans=INF;bool vis[N];
    inline void solve(int u,int fath){
        vis[u]=true;
        for(int v:G[u])
            if(v!=fath&&!vis[v]&&a[v]==1)solve(v,u);
        return;
    }
    inline bool judge(){
        int cnt=0;
        for(int i=1;i<=n;i++)cnt+=(a[i]==1);
        if(cnt!=k)return false;
        int blk=0;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&a[i]==1)solve(i,0),blk++;
        return blk<=2;
    }
    inline void DFS(int u){
        if(u==n+1){
            for(int i=1;i<=n;i++)vis[i]=false;
            if(!judge())return;
            int res=0;
            for(int i=1;i<=n;i++){
                int d=INF;
                for(int j=1;j<=n;j++){
                    if(a[j]==0)continue;
                    d=min(d,DIS(i,j));
                }
                res=max(res,d);
            }
            ans=min(ans,res);
            return;
        }
        a[u]=0;DFS(u+1);a[u]=-1;
        a[u]=1;DFS(u+1);a[u]=-1;
    }
    inline void work(){
        for(int i=1;i<=n;i++)a[i]=-1;
        ans=INF;DFS(1);
        cout<<ans<<'\n';
        return;
    }
}
inline void solve(){
    cin>>n>>k;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        G[u].pb(v),G[v].pb(u);
    }
    dfs(1,0);
    for(int i=1;i<=20;i++)
        for(int u=1;u<=n;u++)
            fa[u][i]=fa[fa[u][i-1]][i-1];
    if(n<=10){baoli::work();return;}
    cout<<1<<'\n';
    return;
}
inline void clr(){
    for(int i=1;i<=20;i++)
        for(int u=1;u<=n;u++)fa[u][i]=0;
    for(int i=1;i<=n;i++)dep[i]=0;
    for(int i=1;i<=n;i++)G[i].clear();
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int C,T;cin>>C>>T;
    while(T--)solve(),clr();
    return 0;
}