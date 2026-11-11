#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500001],k[501],f[501][501],a,t,x,y;
vector<pair<long long,long long> >p[500001];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
        {
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++)scanf("%lld%lld",&a,&t),p[a].push_back({i,t});
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)f[i][j]=1e18;
            else f[i][j]=0;
    for(int i=1;i<=m;i++)
        for(int j=0;j<(int)p[i].size();j++)
            for(int k=0;k<(int)p[i].size();k++)
                f[p[i][j].first][p[i][k].first]=min(f[p[i][j].first][p[i][k].first],p[i][j].second+p[i][k].second);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1;i<=q;i++)
        {
        scanf("%lld%lld",&x,&y);
        long long ans=1e18;
        for(int j=0;j<(int)p[x].size();j++)
            for(int k=0;k<(int)p[y].size();k++)
                ans=min(ans,w[x]+p[x][j].second+f[p[x][j].first][p[y][k].first]+p[y][k].second+w[y]);
        printf("%lld\n",ans);
        }
    return 0;
}
