#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<pair<int,long long>> v[500005];
long long dis[505][505];
int main(){freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        int o; scanf("%d",&o);
        for(int j=1;j<=o;j++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back({i,y});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++)
        for(int a=0;a<v[i].size();a++)
            for(int b=a+1;b<v[i].size();b++){
                dis[v[i][a].first][v[i][b].first]=min(dis[v[i][a].first][v[i][b].first],v[i][a].second+v[i][b].second);
                dis[v[i][b].first][v[i][a].first]=min(dis[v[i][a].first][v[i][b].first],v[i][a].second+v[i][b].second);
            }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j&&j!=k&&i!=k) dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(auto p:v[x]) for(auto q:v[y]) ans=min(ans,dis[p.first][q.first]+p.second+q.second+w[x]+w[y]);
        printf("%lld\n",ans);
    }
    return 0;
}
