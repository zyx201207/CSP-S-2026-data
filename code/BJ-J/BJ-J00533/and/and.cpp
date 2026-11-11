#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2010;
const int M = 2e5 + 10;

int n, m;
int a[M];
int dp[N][N];

signed main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;

    int f = 1;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];

        dp[i][1] = a[i];

        if(a[i] & (a[i] + 1) != a[i] + 1)
        {
            f = 0;
        }
    }

    int res = a[1];
    int mx = 0;

    for(int i = 2; i <= n; i++)
    {
        res &= a[i];

        mx = max(mx, a[i]);
    }

    if(f)
    {
        cout << mx << '\n';

        return 0;
    }

    if(m == n)
    {
        cout << res << '\n';

        return 0;
    }

    if(m == n - 1)
    {
        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            int t = res ^ a[i];

            ans = max(ans, t);
        }

        cout << ans << '\n';

        return 0;
    }

    for(int i = 2; i <= n; i++)
    {
        for(int mi = 2; mi <= min(i, m); mi++)
        {
            int maxn = 0;

            for(int j = 1; j < i; j++)
            {
                int t1 = maxn & a[i];
                int t2 = dp[j][mi - 1] & a[i];

                if(t1 < t2)
                {
                    maxn = dp[j][mi - 1];
                }
            }

            dp[i][mi] = a[i] & maxn;
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}