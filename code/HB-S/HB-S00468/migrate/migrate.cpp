#include <bits/stdc++.h>
using namespace std;

int c, t, n, mindep = 1e9 + 7;
long long x[2000005], d, ans, cnt;

void calc(int a, int b, int dep)
{
    if (a == b)
    {
        if (dep < mindep)
        {
            mindep = min(mindep, dep);
            cnt = 1;
        }
        else if (dep == mindep)
            cnt++;
        return;
    }
    for (int i = b; i > a; i--)
    {
        if (x[i] - x[a] <= d)
            calc(i, b, dep + 1);
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--)
    {
        ans = 0;
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &x[i]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                cnt = 0;
                mindep = 1e9 + 7;
                calc(i, j, 0);
                if (cnt == 2)
                    ans++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}