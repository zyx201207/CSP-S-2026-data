#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, dis[302][302], x[2000006], cnt[302][302], inf = 1ll << 60;
void solve24() // floyd o(n^3) 24pts
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = inf;
            cnt[i][j] = 0;
        }
        for (int j = lower_bound(x + 1, x + i + 1, x[i] - d) - x; j < i; j++)
        {
            dis[j][i] = dis[i][j] = 1;
            cnt[i][j] = cnt[j][i] = 1;
        }
        dis[i][i] = 0;
        cnt[i][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (dis[j][k] > dis[j][i] + dis[i][k])
                {
                    dis[j][k] = dis[j][i] + dis[i][k];
                    cnt[j][k] = cnt[j][i] * cnt[i][k];
                }
                else if (dis[j][k] == dis[j][i] + dis[i][k])
                {
                    cnt[j][k] += cnt[j][i] * cnt[i][k];
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (cnt[i][j] == 2)
                ans++;
        }
    }
    cout << ans << '\n';
}
void solveA()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    long long delta;
    delta = x[2] - x[1];
    if (d < 2 * delta)
    {
        cout << "0\n";
        return;
    }
    cout << max(n - (abs(2 * d / delta) - 1), 0ll) << '\n';
    return;
}
void solveB()
{
    cin >> n >> d;
    int tmp = 1, rtm = n;
    bool f = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        if (x[i] - x[1] <= d)
        {
            tmp = i;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (x[i] - x[n] <= d)
        {
            rtm = i;
        }
        else
        {
            break;
        }
    }
    if (tmp == n || rtm == 1 || tmp - rtm >= 2)
    {
        cout << "0\n";
        return;
    }
    if (tmp - rtm)
    {
        long long va = lower_bound(x + 1, x + n + 1, x[tmp + 1] - d) - x, vb = lower_bound(x + 1, x + n + 1, x[rtm - 1] + d) - x;
        cout << (va - 1) * (n - vb) << '\n';
        return;
    }
    else
    {
        long long va = lower_bound(x + 1, x + n + 1, x[tmp - 1] + d) - x - 1, vb = lower_bound(x + 1, x + n + 1, x[tmp + 2] - d) - lower_bound(x + 1, x + n + 1, x[tmp + 1] - d), ans = va * vb;
        va = lower_bound(x + 1, x + n + 1, x[tmp + 1] - d) - x - 1, vb = lower_bound(x + 1, x + n + 1, x[tmp - 1] + d) - lower_bound(x + 1, x + n + 1, x[tmp - 2] + d), ans += va * vb;
        cout << ans << '\n';
        return;
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t--)
    {

        if (c == 11 || c == 12)
            solveA();
        else if (c == 13 || c == 14)
            solveB();
        else
            solve24();
    }
    return 0;
}