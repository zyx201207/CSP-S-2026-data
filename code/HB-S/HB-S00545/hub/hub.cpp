#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int cid,T;
int n,K;
vector<int> e[N];
void clear(){
    for(int i=1;i<=n;i++) e[i].clear();
}
int ans;
bool vis[N];
int dep[N],top[N],son[N],sz[N],fa[N];
void dfs1(int u,int f){
    sz[u]=1;
    son[u]=0;fa[u]=f;
    dep[u]=dep[f]+1;
    for(int v:e[u]){
        if(v==f) continue;
        sz[u]+=sz[v];
        dfs1(v,u);
        if(sz[son[u]]<sz[v]) son[u]=v;
    }
}
void dfs2(int u,int t){
    top[u]=t;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(int v:e[u]){
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[fa[x]]<dep[fa[y]]) swap(x,y);
        x=fa[top[x]];
    }
    if(dep[x]<dep[y]) return x;
    else return y;
}
int dis(int x,int y){
    int lc=lca(x,y);
    return dep[x]+dep[y]-2*dep[lc];
}
bool can[N];
int all;
void solve(int x){
    all++;
    can[x]=1;
    for(int v:e[x]){
        if(can[v]) continue;
        if(!vis[v]) continue;
        solve(v);
    }
}
bool check(){
    for(int i=1;i<=n;i++) can[i]=0;
    all=0;
    for(int i=1;i<=n;i++){
        if(vis[i]&&!can[i]){
            solve(i);
            break;
        }
    } 
    for(int i=1;i<=n;i++){
        if(vis[i]&&!can[i]){
            solve(i);
            break;
        }
    }
    return all==K;
}
void dfs(int u,int cnt){
    if(u==n+1){
        if(cnt!=K) return;
        if(check()){
            int mx=0;
            for(int i=1;i<=n;i++){
                int mi=1e9;
                for(int j=1;j<=n;j++) if(vis[j]) mi=min(mi,dis(i,j));
                mx=max(mx,mi);
            }
            ans=min(ans,mx);
        }
        return;
    }
    vis[u]=0;
    dfs(u+1,cnt);
    vis[u]=1;
    dfs(u+1,cnt+1);
}
void work(){
    cin>>n>>K;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    ans=1e9;
    dfs1(1,0);
    dfs2(1,1);
    dfs(1,0);
    cout<<ans<<"\n";
    clear();
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>cid>>T;
    while(T--) work();
    return 0;
}