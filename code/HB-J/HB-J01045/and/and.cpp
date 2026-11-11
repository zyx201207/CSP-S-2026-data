#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
int a[200010],dp[20000][20000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][0]=a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i][j-1]&a[i]);
        }
    }
    cout<<dp[n][m]<<'\n';
    return 0;
}
