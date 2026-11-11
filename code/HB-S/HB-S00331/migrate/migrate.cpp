#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5;
int c,t,n,d,a[N],f[N],dp[N][2][2],dp1[N][2][2],ans;

inline int read ()
{
    int x=0,f=1;
    char c=getchar();
    while (c<'0'||c>'9')
    {
        if (c=='-') f=-f;
        c=getchar();
    }
    while (c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

inline int lower (int x)
{
    int l=1,r=n,mid,res=0;
    while (l<=r)
    {
        mid=l+r>>1;
        if (a[mid]<=x) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}

inline void DP (int x,int y)
{
    if (x+1==y)
    {
        dp[y][0][0]++;
        dp[y][0][0]+=dp[x][0][0];
        dp[y][1][0]+=dp[x][1][0];
        if (x>2&&a[x-2]+d>=a[y]) return ;
        if (x>1&&a[x-1]+d>=a[y]) dp[y][1][0]+=dp[x][0][1];
        else dp[y][1][0]+=dp[x][1][1],dp[y][0][0]+=dp[x][0][1];
    }
    else
    {
        dp[y][0][1]++;
        dp[y][0][1]+=dp[x][0][0];
        dp[y][1][1]+=dp[x][1][0];
        if (x>2&&a[x-2]+d>=a[y]) return ;
        if (x>1&&a[x-1]+d>=a[y]) dp[y][1][1]+=dp[x][0][1];
        else dp[y][1][1]+=dp[x][1][1],dp[y][0][1]+=dp[x][0][1];
    }
}

inline void DP1 (int x,int y)
{
    if (x+1==y)
    {
        dp1[y][0][0]++;
        dp1[y][0][0]+=dp[x][0][0];
        dp1[y][1][0]+=dp[x][1][0];
        if (x>2&&a[x-2]+d>=a[y]) return ;
        if (x>1&&a[x-1]+d>=a[y]) dp1[y][1][0]+=dp[x][0][1];
        else dp1[y][1][0]+=dp1[x][1][1],dp1[y][0][0]+=dp[x][0][1];
    }
    else
    {
        dp1[y][0][1]++;
        dp1[y][0][1]+=dp[x][0][0];
        dp1[y][1][1]+=dp[x][1][0];
        if (x>2&&a[x-2]+d>=a[y]) return ;
        if (x>1&&a[x-1]+d>=a[y]) dp1[y][1][1]+=dp[x][0][1];
        else dp1[y][1][1]+=dp[x][1][1],dp1[y][0][1]+=dp[x][0][1];
    }
}

inline void solve ()
{
    n=read(),d=read();
    ans=0;
    for (int i=1;i<=n;i++) a[i]=read();
    int is1=1;
    for (int i=3;i<=n;i++) if (a[i]-a[i-1]!=a[i-1]-a[i-2]) is1=0;
    /*if (t==3)
    {
        cout<<n<<' '<<d<<'\n';
        for (int i=1;i<=n;i++) cout<<a[i]<<' ';
        cout<<'\n';
    }*/
    for (int i=1;i<=n;i++)
        f[i]=lower(a[i]+d),dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=dp1[i][0][0]=dp1[i][0][1]=dp1[i][1][0]=dp1[i][1][1]=0;
    if (is1)
    {
       // cout<<1234123;
        for (int i=1;i<=n;i++)
        {
            ans+=dp[i][1][0]*(f[i]-i);
            ans+=dp[i][1][1]*(f[i]-lower(a[i-1]+d));
            if (i>=2) ans+=(dp[i][0][1]-dp1[i-1][1][1])*max(0ll,(lower(a[i-1]+d))-lower(a[i-2]+d));
            else ans+=(dp[i][0][1]-dp1[i-1][1][1])*max(0ll,(lower(a[i-1]+d))-i);
            ans+=(dp[i][0][0]-dp1[i-1][1][0])*max(0ll,(lower(a[i-1]+d)-i));
            //printf("[%d %d %d %d %d %d %d]\n",i,f[i],dp[i][0][0],dp[i][0][1],dp[i][1][0],(lower(a[i-1]+d)),lower(a[i-2]+d));
            if (f[i]>i) DP(i,f[i]);
            if (f[i]-1>i) DP1(i,f[i]-1);
        }
        cout<<ans<<'\n';
        return ;
    }
    for (int i=1;i<=n;i++)
    {
        ans+=dp[i][1][0]*(f[i]-i);
        ans+=dp[i][1][1]*(f[i]-lower(a[i-1]+d));
        if (i>=2) ans+=max(0ll,(dp[i][0][1]-dp1[i-1][1][1]))*max(0ll,(lower(a[i-1]+d))-lower(a[i-2]+d));
        else  ans+=max(0ll,(dp[i][0][1]-dp1[i-1][1][1]))*max(0ll,(lower(a[i-1]+d))-i);
        ans+=max(0ll,dp[i][0][0]-dp1[i-1][1][0])*max(0ll,(lower(a[i-1]+d)-i));
        //printf("[%d %d %d %d %d %d %d]\n",i,f[i],dp[i][0][0],dp[i][0][1],dp[i][1][0],(lower(a[i-1]+d)),lower(a[i-2]+d));
        if (f[i]>i) DP(i,f[i]);
        //if (f[i]-1>i) DP1(i,f[i]-1);
    }
    cout<<ans<<'\n';
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while (t--) solve();
    return 0;
}
