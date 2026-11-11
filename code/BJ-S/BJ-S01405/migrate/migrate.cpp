#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[305],dp[305][2],ans;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> d;
        for (int i = 1;i <= n;i++)
            cin >> a[i];
        for (int i = 1;i < n;i++)
        {
            for (int as = i;as <= n;as++)
            {
                dp[as][0] = 0x3f3f3f3f;
                dp[as][1] = 0;
            }
            dp[i][0] = 1;
            dp[i][1] = 1;
            for (int as = i + 1;as <= n;as++)
            {
                int x = as - 1;
                while (a[as] - a[x] <= d && x >= i)
                {
                    if (dp[as][0] == dp[x][0] + 1)
                        dp[as][1] += dp[x][1];
                    else if (dp[as][0] > dp[x][0] + 1)
                    {
                        dp[as][0] = dp[x][0] + 1;
                        dp[as][1] = dp[x][1];
                    }
                    x--;
                }
                if (dp[as][1] == 2)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
