#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=1e7+10;
#define LL long long
struct edge{
    int nxt,w,to;
}e[M];
LL hl[M],tot,dis[M],vis[M];
void add(int u,int v,int w){
    e[++tot].to=v;
    e[tot].nxt=hl[u];
    e[tot].w=w;
    hl[u]=tot;
}
struct node{
    int v,p;
    friend bool operator < (node a,node b){
        return a.v>b.v;
    }
};
void dij(int s){
    priority_queue<node> q;
    q.push({0,s});
    vis[s]=1;
    dis[s]=0;
    while(!q.empty()){
        int u=q.top().p;
        q.pop();
        for(int i=hl[u];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].w;
            if(vis[v]) continue;
            vis[v]=1;
            if(dis[v]>=dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
LL tong[N][510],w[N],ww[N][510],k[N][510],cnt[N],ans=INT_MAX;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int n,m,c,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    //for(int i=1;i<=m;i++) printf("%lld ",w[i]);
    for(int i=1,t;i<=n;i++){
        scanf("%lld",&t);
        for(int j=1;j<=t;j++){
            scanf("%lld",&k[j][i]);scanf("%lld",&ww[k[j][i]][i]);
            tong[k[j][i]][++cnt[k[j][i]]]=i;
            for(int l=1;l<cnt[k[j][i]];l++){
                add(l*n+k[j][i],k[j][tong[k[j][i]][l]],ww[k[j][i]][i]+ww[k[j][i]][tong[k[j][i]][l]]);
                add(k[j][tong[k[j][i]][l]],l*n+k[j][i],ww[k[j][i]][i]+ww[k[j][i]][tong[k[j][i]][l]]);
            }
            if(cnt[k[j][i]]<=1 && j!=1){
                add(k[j][i],k[j-1][i],0);
                add(k[j-1][i],k[j][i],0);
            }
        }
    }
    while(q--){
        int s,t;ans=INT_MAX;
        scanf("%d%d",&s,&t);
        for(int j=s;j<=cnt[s]*n;j+=n){
            memset(dis,0x3f,sizeof(dis));
            dij(s);
            for(int i=t;i<=cnt[t]*n;i+=n){
                ans=min(dis[i],ans);
            }
        }
        printf("%lld\n",ans+w[s]+w[t]);
    }
    return 0;
}
