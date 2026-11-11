#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=505,M=500010;
int c,n,m,d,q;ll w[M],dis[N][N];
vector<pii> lis[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        int k; scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a,t; scanf("%d%d",&a,&t);
            lis[a].emplace_back(i,t);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(pii x:lis[i])
            for(pii y:lis[i])
                dis[x.first][y.first]=min(dis[x.first][y.first],(ll)x.second+y.second);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
    while(q--){
        int u,v; scanf("%d%d",&u,&v);
        ll ans=LLONG_MAX;
        for(pii x:lis[u])
            for(pii y:lis[v])
                ans=min(ans,x.second+y.second+dis[x.first][y.first]);
        ans+=w[u]+w[v];
        printf("%lld\n",ans);
    }
    return 0;
}