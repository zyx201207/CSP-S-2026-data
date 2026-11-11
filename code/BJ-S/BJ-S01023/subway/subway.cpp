#include<bits/stdc++.h>
using namespace std;
const long long N=505,M=5e5+10;
//errow M
long long n,m,c,d,qq;
long long ww[M];
long long t[21][M];
long long b[M][21];//每个站包含的线路
long long dis[N][N];
priority_queue<pair<long long,long long> ,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
long long disdij[N];
int vis[N];
long long dij(long long x,long long y){
    for(long long i=1;i<=n;i++){
        vis[i]=0;
        disdij[i]=LONG_LONG_MAX;
    }

    for(long long i=1;i<=d&&(b[x][i]);i++){
        long long sub=b[x][i];
        disdij[sub]=t[i][x];
        q.push({disdij[sub],sub});
    }


    while(q.size()){
        long long u=q.top().second;
        q.pop();
        //if(u==y) break;
        //cout<<u<<endl;
        if(vis[u]) continue;
        vis[u]=1;
        for(long long v=1;v<=n;v++){
            if(v==u) continue;
            if(dis[u][v]!=LONG_LONG_MAX&&disdij[v]>disdij[u]+dis[u][v]){
                disdij[v]=disdij[u]+dis[u][v];
                //cout<<disdij[v]<<endl;
                q.push({disdij[v],v});
            }
        }
        //cout<<disdij[u]<<endl;
    }
    long long ans=LONG_LONG_MAX;
    for(long long i=1;i<=d&&(b[y][i]);i++){
        long long sub=b[y][i];
        if(disdij[sub]==LONG_LONG_MAX) continue;
        ans=min(ans,disdij[sub]+t[i][y]);
    }
    return ans;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&qq);
    for(long long i=1;i<=m;i++){
            scanf("%lld",&ww[i]);
    }
    for(long long i=1;i<=n;i++){//dis init
        for(long long j=1;j<=n;j++) dis[i][j]=LONG_LONG_MAX;
        dis[i][i]=0;
    }

    for(long long i=1;i<=n;i++){
        long long k;

        scanf("%lld",&k);
        for(long long j=1;j<=k;j++){
            long long l,r;//站编号，上升时间

            scanf("%lld %lld",&l,&r);
            //t[i][l]=r;//当前地铁i在站l的时间
            long long p=1;
            for(p=1;b[l][p];p++){//b[l][p]当前站的其他地铁
                long long sub=b[l][p];
                long long t1=t[p][l];
                if(dis[i][sub]>r+t1){
                    dis[sub][i]=dis[i][sub]=r+t1;
                    //cout<<dis[i][b[l][p]]<<endl;
                }
            }
            b[l][p]=i;
            t[p][l]=r;
        }
    }
    for(long long i=1;i<=qq;i++){
        long long x,y;
        scanf("%lld %lld",&x,&y);
        long long d1=dij(x,y);
        //cout<<d1<<endl;
        printf("%lld\n",ww[x]+ww[y]+d1);
    }
    return 0;
}
