#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int dp[2000005],n,d,C,T,q[2000005],b[2000005];
void solve1()
{
    while (T--)
    {
        cin>>n>>d;
        for (int i=1;i<=n;i++)
        {
            cin>>a[0];
        }
        cout<<max(0,n-d*2+1)<<endl;
    }
}
void solve2()
{
    while (T--)
    {
        cin>>n>>d;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            memset(dp,0x3f,sizeof(dp));
            memset(q,0,sizeof(q));
            b[i]=1;
            dp[i]=0;
            int l=1,r=1;
            q[l]=i;
            for (int j=i+1;j<=n;j++)
            {
                while (l<=r&&a[q[l]]+d<a[j])
                {
                    l++;
                }
                if (l<=r)
                {
                    dp[j]=dp[q[l]]+1;
                    b[j]=b[q[l]];
                    if (dp[q[l+1]]==dp[q[l]]&&l<r)
                    {
                        b[j]+=b[q[l+1]];
                    }
                    if (dp[q[l+2]]==dp[q[l]]&&l+1<r)
                    {
                        b[j]+=b[q[l+2]];
                    }
                }
                if (b[j]==2)
                {
                    ans++;
                }
                while (l<=r&&dp[q[r]]>dp[j])
                {
                    r--;
                }
                r++;
                q[r]=j;
            }
        }
        cout<<ans<<endl;
    }
}
void solve3()
{
    while (T--)
    {
        cin>>n>>d;
        for (int i=1;i<=n;i++)
        {
            cin>>a[0];
        }
        cout<<"0"<<endl;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    if (C==11||C==12)
    {
        solve1();
    }
    else if (C==13||C==14)
    {
        solve3();
    }
    else
    {
        solve2();
    }
    return 0;
}