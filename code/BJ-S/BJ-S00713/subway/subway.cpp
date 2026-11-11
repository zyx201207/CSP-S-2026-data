#include<bits/stdc++.h>
using namespace std;
const long long N=510,M=5e5+10,INF=1e15;
long long c,n,m,d,Q;
long long val[N],minn[M],ans[1510][1510];
struct node{
    long long v,t;
};
vector<node>e[N+M];
bool vis[1505];
long long dis[N+M];
void Dijkstra(long long st){
    for(int i=1;i<=n+m;i++)dis[i]=INF,vis[i]=0;
    dis[st]=0;
    while(1){
        long long h=0,minn=1e15;
        for(int i=1;i<=n+m;i++){
            if(!vis[i]&&dis[i]<minn){
                minn=dis[i];
                h=i;
            }
        }
        if(h==0)break;
        vis[h]=1;
        for(int i=0;i<e[h].size();i++){
            long long to=e[h][i].v;
            if(dis[h]+e[h][i].t<dis[to]){
                dis[to]=dis[h]+e[h][i].t;
            }
        }
    }

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);/*zhushi!!!!!!!!!!!!!!!*/
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&val[i]);
    for(int i=1;i<=n;i++){
        long long k=0;
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            long long v=0,t=0;
            scanf("%lld%lld",&v,&t);
            e[i].push_back({v+n,t});
            e[v+n].push_back({i,t});
        }
    }
    for(int i=n+1;i<=n+m;i++){
        minn[i-n]=1e15;
        for(int j=0;j<e[i].size();j++){
            minn[i-n]=min(minn[i-n],e[i][j].t);
        }
    }
    for(int st=n+1;st<=n+m;st++){
        Dijkstra(st);
        //if(st==1+n){
            //for(int i=1;i<=n+m;i++)cout<<dis[i]<<" ";
        //}
        for(int fin=n+1;fin<=n+m;fin++){
            if(fin==st)continue;
            ans[st-n][fin-n]=dis[fin];
        }
    }
    while(Q--){
        long long u,v;
        scanf("%lld%lld",&u,&v);
        printf("%lld\n",ans[u][v]+val[u]+val[v]);
    }
    return 0;
}
