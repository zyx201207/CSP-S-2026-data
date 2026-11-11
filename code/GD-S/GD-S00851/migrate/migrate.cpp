#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

bool g[5005][5005];
int c, t, n, ans;
long long d, x[5005], f[5005], dis[5005];
queue<int> q;

void bfs(int s)
{
    memset(f, 0, sizeof(f));
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
    f[s] = 1;
    q.push(s);
    int x = 0;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (g[x][i])
            {
                if (dis[i] == -1)
                {
                    f[i] = f[x];
                    dis[i] = dis[x] + 1;
                    q.push(i);
                }
                else if (dis[i] == dis[x] + 1)
                {
                    f[i] += f[x];
                }
            }
        }
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--)
    {
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", x + i);
        }
        memset(g, false, sizeof(g));
        for (int i = 1; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (llabs(x[i] - x[j]) <= d)
                {
                    g[i][j] = g[j][i] = true;
                }
            }
        }
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            bfs(i);
            for (int j = 1; j <= n; ++j)
            {
                if (f[j] == 2)
                {
                    ++ans;
                }
            }
        }
        printf("%d\n", ans >> 1);
    }
    return 0;
}