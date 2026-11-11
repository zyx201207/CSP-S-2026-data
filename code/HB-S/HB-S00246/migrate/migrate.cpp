#include <bits/stdc++.h>
using namespace std;
int c, t;
const int N = 2e6 + 4;
long long a[N];
long long d;
int s[N];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t--)
    {
        // memset(s,0, sizeof(n));
        int n;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        int cnt = n;

        for (int i = n; i >= 1; --i)
        {
            while (a[i] + d < a[cnt])
                cnt--;
            s[i] = cnt;
        }

        vector<int> dp(n + 1, 0);
        for (int i = n - 3; i >= 1; --i)
        {
            if (s[i] - i == 2)
            {
                if (s[i] != s[s[i]])
                    dp[i] = dp[s[i]] + s[i + 1] - s[i];
                else
                    dp[i] = dp[s[i]] + dp[s[i] + 1] - dp[s[i]];
            }

            else if (s[i] - i == 1)
                dp[i] = dp[s[i]] + dp[s[i] + 1] - dp[s[i]];
            
            else if (s[i] == i)
                dp[i] = dp[i + 1];
                
            else
                dp[i] = dp[s[i]] + s[s[i] - 1] - s[s[i] - 2];
            if (s[i] - i > 1)
                dp[i] += dp[i + 1];
        }
        cout << dp[1] << '\n';
    }
}
