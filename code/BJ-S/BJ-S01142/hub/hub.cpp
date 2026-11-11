#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int c,t,cnt,head[maxn],js,dfn[maxn],low[maxn],col,colour[maxn];
ll dist[maxn],dp[maxn];
stack<int> zhan;
bool vis[maxn];
struct Edge{
    int to;
    int next;
}edge[maxn];
void add(int u,int v){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int u,int fa){
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa){
            continue;
        }
        dfs(v,u);
        dist[u]=dist[v]+1;
    }
}
void Tarjan(int u){
    dfn[u]=low[u]=++js;
    zhan.push(u);
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(dfn[v]==0){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(colour[v]==0){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        colour[u]=++col;
        while(zhan.top()!=u){
            colour[zhan.top()]=col;
            zhan.pop();
        }
        zhan.pop();
    }
}
void dfs2(int u,int fa){
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa){
            continue;
        }
        dfs2(v,u);
        dp[u]=max(dp[u],dp[v]+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        memset(dist,0,sizeof(dist));
        memset(vis,false,sizeof(vis));
        ll ans=INF;
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++){
            if(dfn[i]==0){
                Tarjan(i);
            }
        }
        if(col>2){
            cout<<0<<endl;
        }
        for(int i=1;i<=n;i++){
            vis[i]=true;
            dfs2(i,0);
            for(int j=i+1;j<=n;j++){
                vis[j]=true;
                dfs2(j,0);
                vis[j]=false;
                ans=min(ans,dp[i]);
            }
            vis[i]=false;
        }
        cout<<ans<<endl;
    }
    return 0;
}