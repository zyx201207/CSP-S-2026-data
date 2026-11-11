#include<bits/stdc++.h>
using namespace std;
long long w[500005],t[505][500005],a[505][505],g[100005];
long long l,r,ans,maxn;
int main()
{   freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(long long i=1;i<=n;i++)
    {    for(long long j=1;j<=n;j++)
            a[i][j]=2000000005;
    }
    for(long long i=1;i<=m;i++)
        scanf("%lld",&w[i]);
    for(long long i=1;i<=n;i++)
    {   long long k;
        scanf("%lld",&k);
        long long j,tt;
        for(long long s=1;s<=k;s++)
        {   scanf("%lld%lld",&j,&tt);
            t[i][j]=tt;
            for(long long p=1;p<i;p++)
                if(t[p][j]!=0)
                {   a[p][i]=min(a[p][i],t[i][j]+t[p][j]);
                    a[i][p]=min(a[i][p],t[i][j]+t[p][j]);
                }
        }
    }

    for(long long i=1;i<=n;i++)
        a[i][i]=0;
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=n;j++)
            for(long long k=1;k<=n;k++)
                if(i!=j and i!=k and j!=k)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    for(long long i=1;i<=q;i++)
    {   scanf("%lld%lld",&l,&r);
        ans=w[l]+w[r];
        maxn=2000000009;
        for(long long k=1;k<=n;k++)
            for(long long j=1;j<=n;j++)
                if(t[j][r]!=0 and t[k][l]!=0)
                    maxn=min(maxn,t[j][r]+t[k][l]+a[k][j]);
        g[i]=ans+maxn;
    }
    for(long long i=1;i<=q;i++)
        cout<<g[i]<<endl;
    return 0;
}
