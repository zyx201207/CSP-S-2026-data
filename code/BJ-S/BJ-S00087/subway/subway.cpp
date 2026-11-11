#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,q;
ll w[500010],dis[510][510];
vector<pair<int,ll> > v[500010];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%*d %d %d %*d %d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        for(int j=i+1;j<=n;j++){
            dis[i][j]=4e18;
        }
    }
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        for(int j=1;j<=num;j++){
            int x;
            ll y;
            scanf("%d %lld",&x,&y);
            v[x].emplace_back((pair<int,ll>){i,y});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<v[i].size();j++){
            for(int k=j+1;k<v[i].size();k++){
                dis[v[i][j].first][v[i][k].first]=min(dis[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dis[j][i]=dis[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        ll ans=4e18;
        for(int j=0;j<v[x].size();j++){
            for(int k=0;k<v[y].size();k++){
                ans=min(ans,v[x][j].second+v[y][k].second+dis[v[x][j].first][v[y][k].first]);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
