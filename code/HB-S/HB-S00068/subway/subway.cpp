#include <bits/stdc++.h>
using namespace std;
const int N=510,M=500010;
using ll=long long;
const ll inf=1e18;
struct node{int x,y;};
int cid,n,m,d,Q,w[M];
vector<node>v[N];
int tot[M],book[M];
ll dis[N][N];
node a[M][21];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&cid,&n,&m,&d,&Q);
    for(int i=1;i<=m;i++)scanf("%d",w+i);
    for(int i=1,k;i<=n;i++){
        scanf("%d",&k);
        for(int j=1,x,y;j<=k;j++){
            scanf("%d%d",&x,&y);
            v[i].push_back({x,y});
            ++tot[x];
            a[x][tot[x]]={i,y};
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)book[j]=-1;
        for(node u:v[i])book[u.x]=u.y;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            dis[i][j]=inf;
            for(node u:v[j])if(~book[u.x]){
                ll t=book[u.x]+u.y;
                if(dis[i][j]>t)dis[i][j]=t;
            }
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)if(dis[i][k]!=inf){
        for(int j=1;j<=n;j++)if(dis[k][j]!=inf){
            ll t=dis[i][k]+dis[k][j];
            if(dis[i][j]>t)dis[i][j]=t;
        }
    }
    while(Q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=inf;
        for(int i=1;i<=tot[x];i++)for(int j=1;j<=tot[y];j++){
            ll t=dis[a[x][i].x][a[y][j].x]+a[x][i].y+a[y][j].y;
            if(ans>t)ans=t;
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}