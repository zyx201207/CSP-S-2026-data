#include<bits/stdc++.h>
using namespace std;
struct p
{
    long long minn;
    long long num;
}dp[2000006];
long long a[2000006];
long long b[2000006];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    for(long long i=1;i<=t;i++)
    {
        long long n,d;
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
        {
            a[i]=0;
        }
        cin>>b[1];
        for(long long j=2;j<=n;j++)
        {
            cin>>b[j];
            a[j-1]=b[j]-b[j-1];
        }
        long long ans=0;
        for(long long k=2;k<=n;k++)
        {
            dp[k-1].minn=0;
            dp[k-1].num=1;
            for(long long j=k;j<=n;j++)
            {
                dp[j].minn=1e9;
                dp[j].num=1e9;
            }
            for(long long j=k;j<=n;j++)
            {
                long long sum=0;
                for(long long z=j-1;z>=k-1;z--)
                {
                    sum+=a[z];
                    if(sum>d)
                    {
                        break;
                    }
                    if(dp[z].minn+1==dp[j].minn)
                    {
                        dp[j].num+=dp[z].num;
                    }
                    else if(dp[z].minn+1<dp[j].minn)
                    {
                        dp[j].num=1;
                        dp[j].minn=dp[z].minn+1;
                    }
                }
            }
            for(long long j=k-1;j<=n;j++)
            {
                if(dp[j].num==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
