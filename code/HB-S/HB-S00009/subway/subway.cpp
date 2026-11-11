#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
const int N = 5e5 + 10, M = 510, INF = 2e18;
int C, n, m, d, q;
int dis[M][M], w[N];
vector<pii> vec[N];

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> C >> n >> m >> d >> q;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            if (i == j) continue;
            dis[i][j] = INF;
        }
    for (int i = 1; i <= m; i ++ ) cin >> w[i];
    for (int i = 1; i <= n; i ++ )
    {
        int len;
        cin >> len;
        for (int j = 1; j <= len; j ++ )
        {
            int x, v;
            cin >> x >> v;
            vec[x].push_back({i, v});
        }
    }
    for (int i = 1; i <= m; i ++ )
    {
        for (int j = 0; j < (int)vec[i].size(); j ++ )
            for (int k = 0; k < (int)vec[i].size(); k ++ )
            {
                if (k == j) continue;
                int x = vec[i][j].first, vx = vec[i][j].second;
                int y = vec[i][k].first, vy = vec[i][k].second;
                dis[x][y] = min(dis[x][y], vx + vy);
            }
    }
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q -- )
    {
        int a, b;
        cin >> a >> b;
        int ans = INF;
        for (int j = 0; j < (int)vec[a].size(); j ++ )
            for (int k = 0; k < (int)vec[b].size(); k ++ )
            {
                int x = vec[a][j].first, vx = vec[a][j].second;
                int y = vec[b][k].first, vy = vec[b][k].second;   
                ans = min(ans, vx + vy + dis[x][y] + w[a] + w[b]);            
            }
        cout << ans << '\n';
    }

    return 0;
}
