#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5;
const int N=505;
const int INF=5e17;
int c,n,m,d,q,w[M],k,x,y,t[M][N];
//m:number of stations
//n:number of lines
vector<int> station[M];//station i passed line
int e[N][N],dis[N][N];
void floyd()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
                dis[i][j]=e[i][j];//+e[n+1][i]+e[j][n+1];
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);//-2*e[n+1][k]);
            }
        }
    }

        /*for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                cout<<i<<" "<<j<<" "<<dis[i][j]<<"!\n";
            }
        }*/
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)   cin>>w[i];
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            t[i][j]=INF;
    for(int i=1;i<=n;++i)
    {
        cin>>k;
        for(int j=1;j<=k;++j)
        {
            cin>>x;
            cin>>t[x][i];
            station[x].push_back(i);
        }
    }
    for(int i=1;i<=n+1;++i)
        for(int j=1;j<=n+1;++j)
            if(i!=j)
                e[i][j]=INF;
    for(int i=1;i<=m;++i)
    {
        for(int j:station[i])
        {
            for(int k:station[i])
            {
                if(j!=k)
                    e[j][k]=min(e[j][k],t[i][j]+t[i][k]);
            }
        }
    }
    /*for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            e[n+1][j]=e[j][n+1]=min(e[n+1][j],t[i][j]);*/
    /*for(int i=1;i<=m;++i)
    {
        for(int j:station[i])
        {
            for(int k:station[i])
            {
                cout<<i<<" "<<j<<" "<<k<<" "<<e[j][k]<<"\n";
            }
        }
    }*/
        /*for(int j=1;j<=n;++j)
            cout<<e[n+1][j]<<" "<<e[j][n+1]<<"\n";*/
    floyd();
    while(q--)
    {
        cin>>x>>y;
        int ans=INF;
        for(int u:station[x])
        {
            for(int v:station[y])
            {
                ans=min(ans,dis[u][v]+t[x][u]+t[y][v]);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
