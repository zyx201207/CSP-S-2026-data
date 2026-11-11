#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;

long long x[N];
long long arr[N];
long long dp[N];


void work()
{
    long long n,d;
    cin>>n>>d;

    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }

    long long ans=0;

    for(int t=1;t<=n;t++)
    {
        memset(dp,0,sizeof(dp));
        for(int i=t+1;i<=n;i++)
        {
            double dd=d;
            double k=x[i]-x[t];
            dp[i]=ceil(k/dd);
            if(x[i]-x[i-1]>d)
            {
                dp[i]=-1;
            }
            //cout<<dp[i]<<' ';
        }

        for(int i=t;i<=n;i++)
        {
            int dis=x[i]-x[t];
            int mx=d*dp[i];
            if(mx-dis==1&&dp[i]>1)
            {
                ans++;
            }
        }
    }

    cout<<ans<<'\n';
    return ;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    long long c,T;
    cin>>c>>T;

    while(T--)
    {
        work();
    }

    return 0;
}

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
