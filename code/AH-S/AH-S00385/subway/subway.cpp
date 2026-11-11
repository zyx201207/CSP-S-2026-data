#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef pair<int,int> P;
int C,n,m,d,q;
namespace P11{
    const int N=505,M=1005,Q=1e5+5;
    int W[M],k[N],x[Q],y[Q];
    bool need[M];
    int head[N+M],nxt[M<<1],to[M<<1],w[M<<1],tot;
    void add(int u,int v,int x){
        nxt[++tot]=head[u];
        to[tot]=v;
        w[tot]=x;
        head[u]=tot;
    }
    int dis[N+M][N+M];
    bool vis[N+M];
    void dijkstra(int st){
        memset(dis[st],0x3f,sizeof(dis[st]));
        memset(vis,0,sizeof(vis));
        priority_queue<P,vector<P>,greater<P> >q;
        q.push(P(0,st));
        dis[st][st]=0;
        while(!q.empty()){
            P h=q.top();q.pop();
            int u=h.second;
            if(vis[u]) continue;
            vis[u]=1;
            for(int i=head[u];i;i=nxt[i]){
                int v=to[i];
                if(dis[st][v]>dis[st][u]+w[i]){
                    dis[st][v]=dis[st][u]+w[i];
                    q.push(P(dis[st][v],v));
                }
            }
        }
    }
    void solve(){
        for(int i=1;i<=m;i++){
            scanf("%lld",&W[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%lld",&k[i]);
            for(int j=1,a,t;j<=k[i];j++){
                scanf("%lld%lld",&a,&t);
                add(m+i,a,t),add(a,m+i,t);
            }
        }
        for(int i=1;i<=q;i++){
            scanf("%lld%lld",&x[i],&y[i]);
            need[x[i]]=1;
        }
        for(int i=1;i<=m;i++){
            if(!need[i]) continue;
            dijkstra(i);
        }
        for(int i=1;i<=q;i++){
            printf("%lld\n",dis[x[i]][y[i]]+W[x[i]]+W[y[i]]);
        }
    }
}
namespace P15{
    const int N=505,M=2e4+5,Q=2005;
    int W[M],k[N],x[Q],y[Q],need[M];
    int head[N+M],nxt[M<<1],to[M<<1],tot;
    void add(int u,int v){
        nxt[++tot]=head[u];
        to[tot]=v;
        head[u]=tot;
    }
    int t;
    int dis[Q][N+M];
    void bfs(int st,int cnt){
        queue<int> q;
        memset(dis[cnt],0x3f,sizeof(dis[cnt]));
        dis[cnt][st]=0;
        q.push(st);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=head[u];i;i=nxt[i]){
                int v=to[i];
                if(dis[cnt][v]==inf){
                    dis[cnt][v]=dis[cnt][u]+t;
                    q.push(v);
                }
            }
        }
    }
    void solve(){
        for(int i=1;i<=m;i++){
            scanf("%lld",&W[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%lld",&k[i]);
            for(int j=1,a;j<=k[i];j++){
                scanf("%lld%lld",&a,&t);
                add(m+i,a),add(a,m+i);
            }
        }
        for(int i=1;i<=q;i++){
            scanf("%lld%lld",&x[i],&y[i]);
            need[x[i]]=1;
        }
        int tot=0;
        for(int i=1;i<=m;i++){
            if(!need[i]) continue;
            bfs(i,++tot);
            need[i]=tot;
        }
        for(int i=1;i<=q;i++){
            printf("%lld\n",dis[need[x[i]]][y[i]]+W[x[i]]+W[y[i]]);
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
    if(C<=11){
        P11::solve();
    }else if(C<=19){
        P15::solve();
    }else{
        P11::solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
