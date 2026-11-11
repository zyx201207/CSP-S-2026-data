#include<iostream>
using namespace std;
const long long INF=1e18;
long long c,n,m,d,q,w[1005],a[505][1005],t[505][1005],g[1005][1005],k[505],x,y;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==j)
            {
                g[i][j]=0;
            }
            else
            {
                g[i][j]=INF;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<=k[i];j++)
        {
            for(int p=j+1;p<=k[i];p++)
            {
                g[a[i][j]][a[i][p]]=t[i][j]+t[i][p];
                g[a[i][p]][a[i][j]]=t[i][j]+t[i][p];
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=m;k++)
            {
                if(i!=j&&i!=k&&j!=k)
                {
                    if(g[i][k]!=INF&&g[k][j]!=INF)
                    {
                        if(g[i][j]>g[i][k]+g[k][j])
                        {
                            g[i][j]=g[i][k]+g[k][j];
                            g[j][i]=g[i][k]+g[k][j];
                        }
                    }
                }
            }
        }
    }
    while(q--)
    {
        cin>>x>>y;
        cout<<g[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}

