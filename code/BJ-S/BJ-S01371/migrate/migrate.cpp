
#include <bits/stdc++.h>
using namespace std;

long long c, tt, n, m, a[2000005], vis[2000005], ans, flaag;

void dfs(long long x, long long y, long long cnt)
{
    vis[x] = cnt;
    if (x == y)
    {
        flaag++;
        if (flaag == 2)
        {
            ans++;
        }
        if (flaag == 3)
        {
            ans--;
        }
        return ;
    }
    for (int i=x-1; i>=1; i--)
    {
        if (a[x] - a[i] > m)
        {
            break;
        }
        if (vis[i] >= cnt+1)
        {
            dfs(i, y, cnt+1);
        }
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> tt;
    while (tt--)
    {
        ans = 0;
        bool flag=true;
        cin >> n >> m;
        for (int i=1; i<=n; i++)
        {
            cin >> a[i];
            if (i > 2 && a[i]-a[i-1] != a[2]-a[1])
            {
                flag = false;
            }
        }
        if (flag)
        {
            for (int i=m; i<=n-1; i++)
            {
                if ((i*(a[2]-a[1])+1)%m == 0)
                {
                    ans += n-i;
                }
            }
            cout << ans << endl;
            continue;
        }
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (i != j)
                {
                    for (int k=1; k<=n; k++)
                    {
                        vis[k] = 1e8;
                    }
                    flaag = 0;
                    dfs(i, j, 0);
                }
            }
        }
        cout << ans/2 << endl;
    }
    return 0;
}
