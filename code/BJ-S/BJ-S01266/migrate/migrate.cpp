#include <iostream>
using namespace std;
#define int long long
int a[1000000];
int dp[5000][5000];
int sh[5000][5000];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        int n, d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = 1e9;
            }
        }
        for(int i = 1; i <= n; i++) dp[i][i] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(a[j] - a[i] <= d)
                {
                    dp[i][j] = 1;
                }
            }
        }
        for(int i = 1;  i <= n; i++)
        {
            for(int j = i + 2; j <= n; j++)
            {
                for(int k = i + 1; k <= j - 1; k++)
                {
                    if(dp[i][j] == dp[i][k] + dp[k][j])
                    {
                        sh[i][j]++;
                    }
                    else if(dp[i][j] > dp[i][k] + dp[k][j])
                    {
                        sh[i][j] = 1;
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(sh[i][j] == 2)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}/*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/