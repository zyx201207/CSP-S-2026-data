#include <bits/stdc++.h>
using namespace std;
const long long N=5005;
long long w[N],dis[N][N],a[N][N],t[N][N],s[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    long long sum=m;
    for(long long i=1;i<=n;i++)
    {
        cin>>s[i];
        sum=sum+s[i];
        for(long long j=1;j<=s[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(long long i=1;i<=sum;i++)
    {
        for(long long j=1;j<=sum;j++)
        {
            dis[i][j]=1e18;
        }
        dis[i][i]=0;
    }
    long long cnt=m;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=s[i];j++)
        {
            dis[a[i][j]][cnt+j]=dis[cnt+j][a[i][j]]=t[i][j];
            for(long long k=j+1;k<=s[i];k++)
            {
                dis[cnt+j][cnt+k]=dis[cnt+k][cnt+j]=0;
            }
        }
        cnt=cnt+s[i];
    }
    for(long long k=1;k<=sum;k++)
    {
        for(long long i=1;i<=sum;i++)
        {
            for(long long j=1;j<=sum;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        long long u,v;
        cin>>u>>v;
        cout<<dis[u][v]+w[u]+w[v]<<endl;
    }
    return 0;
}
