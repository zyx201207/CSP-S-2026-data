#include<bits/stdc++.h>
using namespace std;
unsigned long long n, m, a[200010], sum, dp[200010], maxn;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(unsigned long long i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    for(unsigned long long i=1; i<=n; i++)
    {
        for(unsigned long long j=m; j>=1; j--)
        {
            if(!dp[j-1])
                dp[j]=max(dp[j], a[i]);
            else
                dp[j]=max(dp[j], dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
    return 0;
}