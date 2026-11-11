#include<bits/stdc++.h>
using namespace std;
const long long N=505,M=5e5+5,inf=1e18;
long long w[M];
vector<pair<long long,long long> > a[M<<1];
long long f[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long i,j,k,n,m,l,r,x,y,s=0,o,d,c,q;
    cin>>c>>n>>m>>d>>q;
    for(i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>k;
        for(j=1;j<=k;j++)
        {
            cin>>x>>y;
            a[x].push_back({i,y});
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            f[i][j]=inf;
        }
        f[i][i]=0;
    }
    for(i=1;i<=m;i++)
    {
        for(j=0;j<a[i].size();i++)
        {
            for(k=j+1;k<a[i].size();k++)
            {
                long long u=a[i][j].first;
                long long v=a[i][k].first;
                f[u][v]=f[v][u]=min(a[i][j].second+a[i][k].second,f[u][v]);
            }
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--)
    {
        cin>>x>>y;
        s=inf;
        for(i=0;i<a[x].size();i++)
        {
            for(j=0;j<a[y].size();j++)
            {
                long long u=a[x][i].first;
                long long v=a[y][j].first;
                // cerr<<u<<"-"<<v<<":"<<f[u][v]<<"\n";
                s=min(s,f[u][v]+a[x][i].second+a[y][j].second);
            }
        }
        // cerr<<s<<"\n";
        cout<<w[x]+w[y]+s<<"\n";
    }
    return 0;
}