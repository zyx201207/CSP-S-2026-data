#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 500+10, N = 4e5+10;
vector<int> subways[M], stations[N];
int w[N];
int _times[M][N];
int a, b, ans = LLONG_MAX;
bool vis[M][N];
void dfs(int x, int id, bool flag, int cnt)
{
    if (vis[id][x]) return;
    vis[id][x] = 1;
    if (subways[id][x] == b)
    {
        cnt += _times[id][x];
        ans = min(ans, cnt);
        return;
    }
    if (flag)
    {
        dfs(x+1, id, 0, cnt);
        return;
    }
    if (subways[id].size()-1 != x)
    {
        dfs(x+1, id, 0, cnt);
    }
    for (int tmp : stations[x])
    {
        if (tmp == id) continue;
        if (subways[tmp][subways[tmp].size()-1] != subways[id][x])
        {
            for (int i = 1; i < subways[tmp].size(); ++i)
            {
                if (subways[tmp][i] == x)
                {
                    dfs(i, tmp, 1, cnt+_times[id][x]+_times[tmp][i]);
                    break;
                }
            }
        }
    }
    vis[id][x] = 0;
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int CCC, n, m, d, q;
    cin >> CCC >> m >> n >> d >> q;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= m; ++i)
    {
        int k;
        cin >> k;
        subways[i].push_back(k);
        for (int j = 1; j <= k; ++j)
        {
            int s, t;
            cin >> s >> t;
            subways[i].push_back(s);
            _times[i][j] = t;
            stations[s].push_back(i);
        }
    }
    while (q--)
    {
        memset(vis, 0, sizeof(vis));
        cin >> a >> b;
        for (int x : stations[a])
        {
            for (int i = 1; i < subways[x].size(); ++i)
            {
                if (subways[x][i] == a)
                {
                    dfs(i, x, 0, _times[x][i]);
                    break;
                }
            }
        }
        cout << ans + w[a] + w[b] << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
