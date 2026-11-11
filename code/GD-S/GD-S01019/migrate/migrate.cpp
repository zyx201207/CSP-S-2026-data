#include <cstdio>
#include <iostream>
#define MAXN 5003
using namespace std;
using lli = long long;

namespace SpecA
{
    void solve(int t)
    {
        int n;
        lli d, ap1, ap2;
        while (t--)
        {
            cin >> n >> d;
            if (n == 1)
            {
                cin >> d;
                cout << "0\n";
                continue;
            }
            cin >> ap1 >> ap2;
            d /= (ap2 - ap1);
            for (int i = 3; i <= n; ++i)
                cin >> ap1;
            if (d <= 1)
                cout << "0\n";
            else
                cout << max(0LL, n - (d << 1LL) + 1) << '\n';
        }
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int tskid, t, n;
    lli d;
    static lli a[MAXN];
    static pair<int, int> dp[MAXN];
    cin >> tskid >> t;
    if (tskid == 11 || tskid == 12)
    {
        SpecA::solve(t);
        return 0;
    }
    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        int ans = 0;
        for (int i = n; i > 1; --i)
        {
            dp[i] = {0, 1};
            for (int j = i - 1, p = i; j; --j)
            {
                while (a[p] - a[j] > d)
                    --p;
                if (p == j)
                    break;
                dp[j] = {dp[p].first + 1, dp[p].second};
                if (p - 1 > j && dp[p - 1].first == dp[p].first)
                    dp[j].second += dp[p - 1].second;
                if (p - 2 > j && dp[p - 2].first == dp[p].first)
                    dp[j].second += dp[p - 2].second;
                dp[j].second = min(dp[j].second, 3);
                ans += (dp[j].second == 2);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
