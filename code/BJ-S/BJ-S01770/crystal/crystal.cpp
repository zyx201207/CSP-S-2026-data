#include <bits/stdc++.h>
using namespace std;
#define int long long

int MAX(int x,int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int MIN(int x,int y)
{
    if(x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int a[500005],s[500005],dp[500005];
int n,m;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    dp[1] = 1;
    int last = 1;
    for(int i = 2;i <= n;i++)
    {
        dp[i] = dp[i - 1];
        s[i] = s[i - 1] + (i - last) * (a[i] - a[i - 1]);
        int sum = 0;
        int t = last;
        for(int j = last;j <= i - dp[i];j++)
        {
            if(s[i] - sum <= m)
            {
                dp[i] = i - j + 1;
                break;
            }
            t = j + 1;
            sum += (a[i] - a[j]);
        }
        for(int j = last;j <= t - 1;j++)
        {
            s[i] -= (a[i] - a[j]);
        }
        last = t;
        //cout << last << " " << s[i] << "\n";
    }
    cout << dp[n];
    return 0;
}
