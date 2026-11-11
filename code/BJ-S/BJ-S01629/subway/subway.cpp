#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d1,q1,a[2005][2005],w[2005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d1>>q1;
    memset(a,0x3f,sizeof(a));
    for(long long i = 1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(long long i = 1;i<=n;i++)
    {
        long long c;
        cin>>c;
        for(long long j = 1;j<=c;j++)
        {
            long long x,y;
            cin>>x>>y;
            a[m+i][x]=y;
            a[x][m+i]=y;
        }
    }
    for(long long i = 1;i<=n+m;i++) a[i][i]=0;

    for(long long k = 1;k<=n+m;k++)
    {
        for(long long i = 1;i<=n+m;i++)
        {
            for(long long j = 1;j<=n+m;j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    /*
    for(long long i = 1;i<=n+m;i++)
    {
        for(long long j = 1;j<=n+m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    while(q1--)
    {
        long long x,y;
        cin>>x>>y;
        cout<<a[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
