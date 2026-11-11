#include<iostream>
#include<cstdio>
using namespace std;
int head[1000010],from[2000010],to[2000010],nxt[2000010];
int tot_edge;
void add_edge(int u,int v){
    from[tot_edge]=u;
    to[tot_edge]=v;
    nxt[tot_edge]=head[u];
    head[u]=tot_edge;
    tot_edge++;
}
int dp[1000010][2];
int n,dist[1000010],depth[1000010],pa[1000010];
bool vis[1000010];
void dfs(int u,int fa,int cur,int ban){
    dist[u]=cur;
    pa[u]=fa;
    vis[u]=true;
    depth[u]=0;
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(v!=fa  &&  v!=ban){
            dfs(v,u,cur+1,ban);
            depth[u]=max(depth[u],depth[v]+1);
        }
    }
}
void calc(int root,int ban,int id){
    for(int i=0;i<=n+1;i++){
        dp[i][id]=0;
    }
    for(int i=1;i<=n;i++){
        dist[i]=-1;
        vis[i]=false;
    }
    dfs(root,-1,0,ban);
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[root]){
            root=i;
        }
    }
    for(int i=1;i<=n;i++){
        dist[i]=-1;
        vis[i]=false;
    }
    dfs(root,-1,0,ban);
    int Genshin=root;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[Genshin]){
            Genshin=i;
        }
    }
    int g=Genshin;
    while(dist[g]!=dist[Genshin]/2){
        g=pa[g];
    }
    root=g;
    for(int i=1;i<=n;i++){
        dist[i]=-1;
        vis[i]=false;
    }
    dfs(root,-1,0,ban);
    for(int i=1;i<=n;i++){
        if(vis[i]){
            dp[0][id]++;
            dp[depth[i]+1][id]--;
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][id]+=dp[i-1][id];
    }
}
void solve(){
    int k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        head[i]=-1;
    }
    tot_edge=0;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<tot_edge;i+=2){
        calc(from[i],to[i],0);
        calc(to[i],from[i],1);
        for(int j=0;;j++){
            if(dp[j][0]+dp[j][1]<=k){
                ans=min(ans,j);
                break;
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    scanf("%d %d",&c,&T);
    while(T--){
        solve();
    }
    return 0;
}