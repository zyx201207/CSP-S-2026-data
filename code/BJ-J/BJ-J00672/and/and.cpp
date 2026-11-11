#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+10;
long long a[N], n, m;

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    long long dp[N] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[0] = max(dp[0], (long long)a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            dp[2] = max(dp[2], a[i] & a[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= 3; j--)
        {
            dp[j] = max(dp[j], dp[j-1] & a[i]);
        }
    }
    cout << dp[m];
    return 0;
}
