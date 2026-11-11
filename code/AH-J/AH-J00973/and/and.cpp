#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200030];
ll dp[200030];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[0]=1;
    memset(dp,a[1],sizeof(dp));
    for (ll i=1;i<=n;i++)
    {
        for (ll j=m;j>=1;j++)
        {
            if (i<=m)
                dp[j]=dp[j-1]&a[j];
            else
                dp[j]=max(dp[j],dp[j-1]&a[j]);
        }
    }
    cout<<dp[m]<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}