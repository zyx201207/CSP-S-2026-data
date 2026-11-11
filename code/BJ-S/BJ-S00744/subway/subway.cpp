#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int a[1010][1010];
int w[100010];
int dp[505][100010];
int dis[100010];
int g[105][1005][1005];
int t[1010][1010];
struct way
{
    int pre, x;
};
void di(int s)
{
    queue<way> q;
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    q.push({-1, s});
    while(!q.empty())
    {
        way T = q.front();
        for(int i = 1; i <= n; i++)
        {
            for(int to = 1; to <= n; to++)
            {
                if(g[i][T.x][to] > 1e9) continue;
                if(i == T.pre) dis[to] = min(dis[to], dis[T.x]);
                else dis[to] = min(dis[to], dis[T.x] + t[T.pre][to] + t[i][to]);
            }
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    if(m <= 1000)
    {
        for(int i = 1, k; i <= n; i++)
        {
            cin >> k;
            for(int j = 1; j <= k; j++)
            {
                cin >> a[i][j] >> t[i][j];
                g[i][a[i][j-1]][a[i][j]] = g[i][a[i][j]][a[i][j-1]] = 1;
            }
        }
        while(q--)
        {
            int st, ed;
            cin >> st >>ed;
            di(st);
            cout << dis[ed] + w[st] + w[ed] << endl;
        }
    }
    return 0;
}
