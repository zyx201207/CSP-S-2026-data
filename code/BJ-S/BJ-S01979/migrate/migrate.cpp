#include<bits/stdc++.h>
using namespace std;
long long dp[2000005][2][3];
long long x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n;
        long long d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
             cin>>x[i];
             for(int j=0;j<2;j++)
                for(int k=0;k<3;k++)
                    dp[i][j][k]=0;
        }
        for(int i=n,j=n;i>=1;i--)
        {
            while(x[j]-x[i]>d)
            {
                dp[i+1][0][1]++;
                if(j>=i+2) dp[i+2][0][2]++;
                j--;
            }
            dp[i][0][0]=dp[j][0][1]+j-i+1;
            if(x[j]-x[i-1]>d) dp[i][0][1]+=dp[j][0][1];
            else if(i>1&&x[j]-x[i-2]>d) dp[i][0][2]+=dp[j][0][1];
            if(j>i)
            {
                if(j>i+1)
                {
                    dp[i][1][0]=dp[j][1][1]+dp[j][0][2];
                    if(x[j]-x[i-1]>d) dp[i][1][1]=dp[j][1][1];
                    if(x[j-1]-x[i-1]>d) dp[i][1][1]+=dp[j][0][2];
                }
                else
                {
                    dp[i][1][0]=dp[j][1][0];
                    if(x[j]-x[i-1]>d) dp[i][1][1]=dp[j][1][1];
                }
            }
            //cout<<i<<" "<<dp[i][1][0]<<" "<<dp[i][1][1]<<"\n";
            ans+=dp[i][1][0];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
