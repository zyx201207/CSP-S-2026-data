#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cs, t, n;
ll d, ans;
const int N = 305, NN = 2000005;

ll a[NN];
ll dp[N][N][N];

ll read()
{
    ll x = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return f * x;
}

void bf()
{
    ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
                dp[i][j][k] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] - a[i] <= d)
                dp[i][j][1] = 1;
        }
    }
    for (int k = 2; k <= n; k++)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int md = i; md <= j; md++)
                {
                    for (int p = 1; p < k; p++)
                        dp[i][j][k] += dp[i][md][p] * dp[md][j][k - p];
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                //cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
                if (dp[i][j][k] == 2) ans++;
                if (dp[i][j][k] > 0) break;
            }
        }
    }
    printf("%lld\n", ans);
}

void sp_a()
{
    printf("%lld\n", d / (a[2] - a[1]) - 2);
}

void solve()
{
    n = read(), d = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    if (cs == 1 || cs == 2) bf();
    else if (cs == 11 || cs == 12) sp_a();
    else printf("0\n");
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cs = read(), t = read();
    while (t-- > 0) solve();
    return 0;
}
//case1,2, 8pts maybe 16
