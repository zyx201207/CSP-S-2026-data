#include<bits/stdc++.h>
using namespace std;
const int M=5e5+50;
int c,n,m,d,q,cnt,s,K;
long long cs[M],dis[M];
long long k,t,x,y,p[M][5],bes=1e18;
unordered_map<long long,long long> ans;
bool vis[M];
struct edge{
    int to;
    long long w;
};
vector<edge> adj[M];
priority_queue<pair<long long,long long> > pq;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%lld",&cs[i]);
    cnt=m;
    if(c==20||c==21){
        memset(p,0x3f,sizeof(p));
        for(int i=1;i<=n;i++){
            scanf("%lld",&k);
            for(int j=1;j<=k;j++){
                scanf("%d%lld",&s,&t);
                p[s][i]=t;
            }
        }
        for(int i=1;i<=m;i++) bes=min(bes,p[i][1]+p[i][2]);
        while(q--){
            scanf("%lld%lld",&x,&y);
            long long res=min(p[x][1]+p[y][1],p[x][2]+p[y][2]);
            res=min(res,min(p[x][1]+p[y][2],p[x][2]+p[y][1])+bes);
            printf("%lld\n",res+cs[x]+cs[y]);
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k);
        K+=k;
        for(int j=1;j<=k;j++){
            scanf("%d%lld",&s,&t);
            cnt++;
            if(j!=1) adj[cnt].push_back({cnt-1,0}),adj[cnt-1].push_back({cnt,0});
            adj[cnt].push_back({s,t});
            adj[s].push_back({cnt,t});
        }
    }
    while(q--){
        scanf("%lld%lld",&x,&y);
        if(ans[x*M+y]){printf("%lld\n",ans[x*M+y]);continue;}
        for(int i=1;i<=K+m+5;i++) dis[i]=1e18,vis[i]=0;
        pq.push({0,x}),dis[x]=0;
        while(!pq.empty()){
            int u=pq.top().second;pq.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(auto p:adj[u]){
                if(dis[u]+p.w<dis[p.to]) dis[p.to]=dis[u]+p.w,pq.push({-dis[p.to],p.to});
            }
        }
        for(int i=1;i<=m;i++) ans[x*M+i]=ans[i*M+x]=dis[i]+cs[x]+cs[i];
        printf("%lld\n",ans[x*M+y]);
    }
    return 0;
}