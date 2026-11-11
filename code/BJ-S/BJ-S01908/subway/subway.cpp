#include<bits/stdc++.h>
using namespace std;
const int M=500000;
const int N=500;
int c,n,m,D,Q;
long long w[M+5];
struct Edge{
    int a;
    long long t;
};
vector<Edge> pe[M+5],qe[N+5];
long long dist[N+5][N+5],d[N+5];
bool vis[N+5];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&D,&Q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a;
            long long t;
            scanf("%d%lld",&a,&t);
            pe[a].push_back(Edge{i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto x:pe[i]){
            for(auto y:pe[i]){
                if(x.a<=y.a) continue;
                qe[x.a].push_back(Edge{y.a,x.t+y.t});
                qe[y.a].push_back(Edge{x.a,x.t+y.t});
            }
        }
    }
    priority_queue<pair<long long,int>> q;
    for(int i=1;i<=n;i++){
        memset(d,0x3f,sizeof(d));
        memset(vis,0,sizeof(vis));
        d[i]=0;
        q.push({0,i});
        while(!q.empty()){
            int u=q.top().second;
            q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(auto v:qe[u]){
                if(d[u]+v.t<d[v.a]){
                    d[v.a]=d[u]+v.t;
                    q.push({-d[v.a],v.a});
                }
            }
        }
        for(int j=1;j<=n;j++){
            dist[i][j]=d[j];
        }
    }
    while(Q--){
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans=1e18;
        for(auto xx:pe[x]){
            for(auto yy:pe[y]){
                ans=min(ans,xx.t+yy.t+dist[xx.a][yy.a]);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
