#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200055];
long long dp[2055][2055],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][1]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=2;j--)
        {
            for(int k=1;k<i;k++)
                dp[i][j]=max(dp[i][j],(dp[i][j-1]&a[k]));
        }
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i][m]);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
