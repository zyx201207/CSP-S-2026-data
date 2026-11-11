
#include <bits/stdc++.h>
using namespace std;
int a[500005];
int dp[500005];
int b[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    int xyz,zzz=1;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<n;i++)
    {
        b[i]=a[i+1]-a[i];
    }
    for (int i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+b[i];
        //cout << b[i] << "\n";
    }
    long long sum=0,ans=0,num=1,l=1,r=1;
    for (int i=2;i<=n;i++)
    {
        if (sum<=m)
        {
            r++;
            sum+=(b[r-1]*num);
            num++;
            //cout << sum << "\n";
        }
        if (sum>m)
        {
            sum-=(dp[r-1]-dp[l]);
            l++;
            num--;
        }
        ans=max(ans,num);
    }
    cout << ans;
    return 0;
}
