#include <bits/stdc++.h>
using namespace std;
int c, T;
int n;
long long d;
long long a[2000005];
int mi = 0;
int cnt;
int cst[2000005];
void dfs(int u, int s, int f, int st)
{
    if (st > cst[u]) return;
    cst[u] = st;
    if (u == f)
    {
        if (mi > st) mi = st, cnt = 1;
        else if (mi == st) cnt ++;
        return;
    }
    // int id = upper_bound(a + u + 1, a + f + 1, a[u] + d + 1) - (a + u)
    // printf("%d->%d: %d\n", s, f, id);
    for (int i = f; i > u; i --)
    {
        
        if (a[i] - a[u] <= d)
        {
            dfs(i, s, f, st + 1);
        }
        // else break;
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T --)
    {
        scanf("%d%lld", &n, &d);
        int res = 0;
        for (int i = 1; i <= n; i ++)
        {
            scanf("%lld", a + i);
        }
        for (int i = 1, j; i <= n; i ++)
        {
            j = lower_bound(a + 1, a + n + 1, a[i] + d + 1) - (a);
            for (; j <= n; j ++)
            {
                mi = 1e9;
                cnt = 0;
                for (int k = i; k <= j; k ++) cst[k] = 1e9;
                dfs(i, i, j, 0);
                if (cnt == 2)
                {
                    res ++;
                    // printf("mi = %d\n", mi);
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}