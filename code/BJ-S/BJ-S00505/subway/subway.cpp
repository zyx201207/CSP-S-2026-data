#include<bits/stdc++.h>
const long long N=110,M=5e3;
long long w[M],dist[M][M],n,t[N][M],c,m,d,q,k[N][M],kk[N],nd[M];
std::pair<long long,long long> dd[M][N];
int main()
{
    std::memset(dist,0x3f,sizeof dist);
    std::freopen("subway.in","r",stdin);
    std::freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;++i)
        std::cin >> w[i];
    for(int i=1;i<=n;++i)
    {
        std::cin >> kk[i];
        for(int j=1;j<=kk[i];++j)
            std::cin >> k[i][j] >> t[i][j],dd[k[i][j]][++nd[k[i][j]]]={i,t[i][j]};
        for(int j=1;j<=kk[i];++j)
        {
            int sum=t[i][j];
            for(int l=j+1;l<=kk[i];++l)
            {
                sum+=t[i][l];
                dist[j][l]=dist[l][j]=sum;
            }
        }
    }
    for(int p=1;p<=m;++p)
    {
        for(int i=1;i<=nd[p];++i)
        {
            for(int j=i+1;j<=nd[p];++j)
            {
                long long cost=dd[p][i].second+dd[p][j].second;
                for(int x=1;x<=kk[dd[p][i].first];++x)
                {
                    for(int y=1;y<=kk[dd[p][j].first];++y)
                    {
                        dist[x][y]=dist[y][x]=std::min(dist[x][y],dist[x][p]+dist[y][p]+cost);
                    }
                }
            }
        }
    }
    while(q--)
    {
        long long x,y;
        std::cin >> x >> y;
        std::cout << w[x]+x[y]+dist[x][y] << '\n';
    }
}
