#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int c,n,k;
vector<int> e[N];
int fa[N],siz[N],dep[N],son[N],top[N];
void dfs1(int u,int f){
    siz[u]=1;
    dep[u]=dep[f]+1;
    fa[u]=f;
    for(auto v:e[u]){
        if(v==f) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int tp){
    top[u]=tp;
    if(!son[u]) return;
    dfs2(son[u],tp);
    for(auto v:e[u]){
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}
int dist(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int a[N],vis[N],col[N];
void check(int u){
    col[u]=1;
    for(auto v:e[u]){
        if(v==fa[u]||!vis[v]) continue;
        check(v);
    }
}
int d[N],minn=1e9;
void dfs(int pos,int start){
    if(pos>k){
        int cnt=0;
        memset(col,0,sizeof(col));
        memset(d,0x3f,sizeof(d));
        for(int i=1;i<=k;i++){
            if(col[a[i]]) continue;
            if(cnt==2) return;
            cnt++;
            check(a[i]);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]){
                d[i]=0;
                continue;
            }
            for(int j=1;j<=k;j++) d[i]=min(d[i],dist(i,a[j]));
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,d[i]);
        minn=min(minn,ans);
        return;
    }
    for(int i=start;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        a[pos]=i;
        dfs(pos+1,i+1);
        vis[i]=0;
    }
}
void solve(){
    memset(son,0,sizeof(son));
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    minn=1e9;
    cin>>n>>k;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,1);
    dfs(1,1);
    cout<<minn<<endl;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int T;cin>>c>>T;
    while(T--) solve();
    return 0;
}
