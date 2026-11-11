#include <bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000005];
long long ans,dp[2000005],cnt[2000005],sum[2000005];
void f(long long l)
{
    dp[l]=0;
    for (int i=1;i<=n;i++) sum[i]=cnt[i]=0,dp[i]=n+1;
    cnt[l]=sum[l]=1;
    for (int i=l+1;i<=n;i++)
    {
        long long lst=lower_bound(a+l,a+i,a[i]-d)-a;
        dp[i]=dp[lst]+1;
        long long rrr=upper_bound(dp+lst,dp+i,dp[lst])-dp-1;
        cnt[i]=sum[rrr]-sum[lst-1];
        if (cnt[i]>2) cnt[i]=3;
        sum[i]=sum[i-1]+cnt[i];
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> T;
    while (T--)
    {
        cin >> n >> d;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        ans=0;
        if (11<=c && c<=12)
        {
            f(1);
            for (int l=2;l<=n;l++)
            {
                if (cnt[l]==2) ans+=(n-l+1);
            }
        }
        else
        {
            for (int l=1;l<=n;l++)
            {
                f(l);
                for (int i=l;i<=n;i++)
                {
                    if (cnt[i]==2)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}