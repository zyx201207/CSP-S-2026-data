#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=5005,P=1e9+7,inf=1e9;

ll rd()
{
    ll x=0,y=1;char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            y=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*y;
}

void wt(int x,char c='~')
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>=10)
        wt(x/10);
    putchar(x%10+'0');
    if(c!='~')
        putchar(c);
}

int n,p[N],f[N][N],g[N][N];
ll d,a[2000005];

void solve()
{
    n=rd();d=rd();
    for(int i=1;i<=n;i++)
        a[i]=rd();
    int j=n;
    for(int i=n;i>=1;i--)
    {
        while(a[j]-a[i]>d)
            j--;
        p[i]=j;
    }
    for(int i=n;i>=1;i--)
    {
        f[i][i]=0;
        for(int j=i+1;j<=p[i];j++)
            f[i][j]=1;
        if(p[i]==i)
            for(int j=i+1;j<=n;j++)
                f[i][j]=inf;
        else
            for(int j=p[i]+1;j<=n;j++)
                f[i][j]=f[p[i]][j]+1;
    }
    ll ans=0;
    for(int i=n;i>=1;i--)
        for(int j=i+1;j<=n;j++)
        {
            if(p[i]>=j)
            {
                g[i][j]=1;
                continue;
            }
            if(f[i][j]>=inf)
            {
                g[i][j]=-1;
                continue;
            }
            if(g[p[i]][j]==0)
            {
                g[i][j]=0;
                continue;
            }
            if(p[i]==i+1)
            {
                g[i][j]=g[i+1][j];
                continue;
            }
            if(p[i]>i+2&&f[p[i]-2][j]==f[p[i]][j])
            {
                g[i][j]=0;
                continue;
            }
            if(f[p[i]][j]==f[p[i]-1][j])
            {
                if(g[p[i]][j]==1&&g[p[i]-1][j]==1)
                    g[i][j]=2;
                else
                    g[i][j]=0;
            }
            else
                g[i][j]=g[p[i]][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(g[i][j]==2)
                ans++;
    printf("%lld\n",ans);
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int op,T;
    op=rd();T=rd();
    while(T--)
        solve();
    return 0;
}