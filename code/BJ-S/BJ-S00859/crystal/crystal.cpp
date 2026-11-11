#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
long long n, m, ans, a[maxn], dp[maxn], sum[maxn];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        long long val = dp[i - 1] * a[i] - (sum[i - 1] - sum[(i - 1) - dp[i - 1]]);
        if(val <= m) dp[i] = dp[i - 1] + 1;
        else
        {
            dp[i] = dp[i - 1];
            val -= a[i] - a[i - dp[i]];
            while(val > m) val -= a[i] - a[i - --dp[i]];
        }
    }
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}
