#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500007],k[507],x,y;
struct qwq{
    long long v,w,nxt;
}edge[500007];
long long head[500007],cnt;
void add(long long u,long long v,long long w){
    edge[++cnt]={v,w,head[u]};
    head[u]=cnt;
}
long long dist[507][507];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(long long i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++){
            long long a,t;
            scanf("%lld %lld",&a,&t);
            add(a,i,t);
        }
    }
    memset(dist,0x3f3f3f3f,sizeof(dist));
    for(int i=1;i<=m;i++){
        for(int j=head[i];edge[j].nxt;j=edge[j].nxt){
            long long v1=edge[j].v,v2=edge[edge[j].nxt].v,w1=edge[j].w,w2=edge[edge[j].nxt].w;
            dist[v1][v2]=min(min(dist[v1][v2],dist[v2][v1]),w1+w2);
            dist[v2][v1]=min(min(dist[v1][v2],dist[v2][v1]),w1+w2);
        }
    }
    for(int i=0;i<=n;i++) dist[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        long long ans=9000000000000000000;
        scanf("%lld %lld",&x,&y);
        for(int j=head[x];j;j=edge[j].nxt){
            for(int k=head[y];k;k=edge[k].nxt){
                ans=min(ans,w[x]+w[y]+edge[j].w+edge[k].w+dist[edge[j].v][edge[k].v]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
