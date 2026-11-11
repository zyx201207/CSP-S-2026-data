#include<iostream>
#include<vector>
using namespace std;
const int N=1e6+5;
vector<int> g[N],a;
int c,t,n,k,u,v,fa[N],sz[N],depth[N],son[N],top[N],ans=1e9;
bool vis[N],vis2[N];
void dfs1(int u,int f){
    sz[u]=1;
    depth[u]=depth[f]+1;
    fa[u]=f;
    for(unsigned int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==f) continue;
        dfs1(v,u);
        if(sz[son[u]]<sz[v]) son[u]=v;
        sz[u]+=sz[v];
    }
}
void dfs2(int u,int tp){
    top[u]=tp;
    if(!son[u]) return;
    else dfs2(son[u],tp);
    for(unsigned int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa[u] || v==son[u]) continue;
        dfs2(v,v);
    }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(depth[top[x]]<depth[top[y]]) swap(x,y);
        x=fa[top[x]];
    }
    return depth[x]<depth[y]?x:y;
}
void dfs3(int u){
    vis2[u]=1;
    for(unsigned int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!vis[v] || vis2[v]) continue;
        dfs3(v);
    }
}
bool check(){
    int cnt=0;
    for(int i:a){
        if(!vis2[i]) dfs3(i),cnt++;
    }
    for(int i=1;i<=n;i++) vis2[i]=0;
    if(cnt>2) return 0;
    return 1;
}
int calc(){
    int maxn=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        int minn=0x3f3f3f3f;
        for(int j:a){
            int t=lca(i,j),cnt=depth[i]-1+depth[j]-1-2*(depth[t]-1);
            //if(vis[3] && vis[4]) printf("%d %d %d %d\n",i,j,t,cnt);
            minn=min(minn,cnt);
        }
        maxn=max(maxn,minn);
    }
    return maxn;
}
void dfs(int x){
    if(x==k+1){

        if(check()){
               //for(int i:a) printf("%d ",i);
    //puts("");
            ans=min(ans,calc());
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            a.push_back(i);
            dfs(x+1);
            vis[i]=0;
            a.pop_back();
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        ans=1e9;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) top[i]=0,depth[i]=0,son[i]=0,g[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs1(1,0);
        dfs2(1,1);
        //for(int i=1;i<=n;i++) printf("%d %d\n",depth[i],son[i]);
        dfs(1);
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
