#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,dp[5005][5005];
long long d,ans,x[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(x[n]-x[1]<=d)
        {
            cout<<"0\n";
            continue;
        }
        if(n<=5000)
        {
            ans=0;
            for(int i=1;i<n;i++)
            {
                for(int l=i,r=i+1;r<=n;r++)
                {
                    while(x[r]-x[l]>d)
                    {
                        l++;
                    }
                    if(l<r)
                    {
                        dp[i][r]=dp[i][l]+1;
                        if(dp[i][l]==dp[i][l+1]&&dp[i][l]!=dp[i][l+2])
                        {
                            ans++;
                        }
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}