#include<bits/stdc++.h>
using namespace std;
#define int long long
int dis[505][505],m,n,c,d,q,x,y,ans;
int w[500005],k[505];
int a_i_j,t_i_j;//lianbian p_(a_i_j)_i=t_i_j
int cnt[500005];
struct dmh{
    int time,id;
}p[500005][25];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        for(int j=i+1;j<=n;j++){
            dis[i][j]=1e17;
            dis[j][i]=1e17;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%lld%lld",&a_i_j,&t_i_j);
            cnt[a_i_j]++;
            p[a_i_j][cnt[a_i_j]].time=t_i_j;
            p[a_i_j][cnt[a_i_j]].id=i;
            //cout<<a_i_j<<' '<<cnt[a_i_j]<<' '<<i<<endl;
            //cout<<k[i]<<endl;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=cnt[i];j++){
            for(int k=j+1;k<=cnt[i];k++){
                //if(j==k)continue;
                int need_time=p[i][j].time+p[i][k].time;
                int u=p[i][j].id,v=p[i][k].id;
                if(dis[u][v]>need_time){
                    dis[u][v]=need_time;
                    dis[v][u]=need_time;
                }
                //cout<<dis[u][v]<<' '<<u<<' '<<v<<' '<<i<<endl;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i==k||j==k||i==j)continue;
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    dis[j][i]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    while(q--){
        scanf("%lld%lld",&x,&y);
        ans=1e17;
        for(int i=1;i<=cnt[x];i++){
            for(int j=1;j<=cnt[y];j++){
                int uu=p[x][i].id,vv=p[y][j].id;
                int jz=p[x][i].time;
                int cz=p[y][j].time;
                ans=min(ans,dis[uu][vv]+jz+cz);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}
