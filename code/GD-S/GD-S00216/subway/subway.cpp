#include <bits/stdc++.h>
using namespace std;
long long dis[505][505], w[500005], sz[500005];
int c, n, m, d, q;
vector<pair<int, long long>> st[500005];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int a;
            long long t;
            cin >> a >> t;
            st[a].push_back({i, t});
        }
    }
    const long long inf = 1LL << 60;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            dis[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        sz[i] = st[i].size();
        for (int j = 0; j < sz[i]; j++)
        {
            for (int k = 0; k < j; k++)
            {
                pair<int, long long> jj = st[i][j];
                pair<int, long long> kk = st[i][k];
                dis[jj.first][kk.first] = min(dis[jj.first][kk.first], jj.second + kk.second);
                dis[kk.first][jj.first] = min(dis[kk.first][jj.first], jj.second + kk.second);
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    while (q--)
    {
        int xr, yr;
        cin >> xr >> yr;
        long long szx = sz[xr], szy = sz[yr];
        long long ans = inf;
        for (int i = 0; i < szx; i++)
        {
            for (int j = 0; j < szy; j++)
            {
                long long tmp = dis[st[xr][i].first][st[yr][j].first] + st[xr][i].second + st[yr][j].second;
                ans = min(ans, tmp);
            }
        }
        ans = ans + w[xr] + w[yr];
        cout << ans << '\n';
    }
    return 0;
}