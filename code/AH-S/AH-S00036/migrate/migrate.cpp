#include <bits/stdc++.h>
using namespace std;

long long x[305], g[305][305];
int cnt[305][305];
long long d;

bool cango(int i, int j)
{
    return abs(x[j] - x[i]) <= d;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;
    while (t--)
    {
        // 初始化
        memset(cnt, 0, sizeof(cnt));
        memset(x, 0, sizeof(x));
        memset(g, 0x7F, sizeof(g));
        // 输入
        int n;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x[i];
        }

        // 类Floyd思想寻找可行路径
        for (int k = 1; k <= n; ++k)
        {
            for (int i = 1; i < k; ++i)
            {
                cnt[i][i] = 0;
                for (int j = k + 1; j <= n; ++j)
                {
                    if (cango(i, k) && cango(k, j))
                    {
                        cnt[i][j] += cnt[i][k] + cnt[k][j];
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (cango(i, j))
                {
                    ++cnt[i][j];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; ++j)
            {
                if (cnt[i][j] == 2)
                {
                    ++ans;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
