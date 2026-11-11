#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 10;
int dis[N][N], sum[N][N];
int x[N], lst[N][N];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    int n, d;
    int i, j, k, len;
    int ans;
    while (t--)
    {
        cin >> n >> d;
        for (i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        memset(dis, 0x3f, sizeof(dis));
        memset(sum, 0, sizeof(sum));
        for (i = 1; i <= n; i++)
        {
            dis[i][i] = 0;
            for (j = i + 1; j <= n && x[j] - x[i] <= d; j++)
            {
                dis[i][j] = 1;
            }
        }
        for (len = 1; len <= n; len++)
        {
            for (i = 1; i + len <= n; i++)
            {
                for (j = i + 1; j < i + len; j++)
                {
                    if (dis[i][j] + dis[j][i + len] < dis[i][i + len])
                    {
                        dis[i][i + len] = dis[i][j] + dis[j][i + len];
                    }
                }
            }
        }
        for (len = 1; len <= n; len++)
        {
            for (i = 1; i + len <= n; i++)
            {
                for(j=1;j<=dis[i][i+len];j++) {
                    for(k=i+1;k<i+len;k++) {
                        sum[i][i+len]+=dis[i][k]==j&&dis[k][i+len]==dis[i][i+len]-j;
                    }
                    sum[i][i+len]--;
                }
            }
        }
        ans = 0;
        for (i = 1; i <= n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                ans += sum[i][j] == 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}