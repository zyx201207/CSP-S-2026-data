#include <cstdio>
#include <cstring>
#include <queue>
#define min(_x, _y) (_x < _y ? _x : _y)
#define max(_x, _y) (_x > _y ? _x : _y)

using namespace std;

struct edge
{
    int next, to;
};

bool vis[15], box[15];
int c, t, n, k, x, y, cnt, ans, cur, minn, maxn, fa[15], head[15], dis[15][15];
queue<int> q;
edge e[25];

inline void add(int u, int v)
{
    ++cur;
    e[cur] = {head[u], v};
    head[u] = cur;
}

int find(int u)
{
    if (u == fa[u])
    {
        return u;
    }
    fa[u] = find(fa[u]);
    return fa[u];
}

inline void bfs(int s)
{
    q.push(s);
    dis[s][s] = 0;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].next)
        {
            if (dis[s][e[i].to] == -1)
            {
                dis[s][e[i].to] = dis[s][x] + 1;
                q.push(e[i].to);
            }
        }
    }
}

void dfs(int step, int chose)
{
    if (step > n)
    {
        if (chose < k)
        {
            return;
        }
        for (int i = 1; i <= n; ++i)
        {
            fa[i] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i])
            {
                for (int j = head[i]; j; j = e[j].next)
                {
                    if (vis[e[j].to])
                    {
                        fa[find(e[j].to)] = find(i);
                    }
                }
            }
        }
        cnt = 0;
        memset(box, false, sizeof(box));
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i])
            {
                box[find(i)] = true;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            cnt += box[i];
        }
        if (cnt < 3)
        {
            maxn = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (vis[i])
                {
                    continue;
                }
                minn = 1e9;
                for (int j = 1; j <= n; ++j)
                {
                    if (vis[j])
                    {
                        minn = min(minn, dis[i][j]);
                    }
                }
                maxn = max(maxn, minn);
                if (maxn >= ans)
                {
                    break;
                }
            }
            ans = min(ans, maxn);
        }
        return;
    }
    if (chose < k)
    {
        vis[step] = true;
        dfs(step + 1, chose + 1);
    }
    vis[step] = false;
    dfs(step + 1, chose);
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        cur = 0;
        memset(head, 0, sizeof(head));
        memset(e, 0, sizeof(e));
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
        }
        memset(dis, -1, sizeof(dis));
        for (int i = 1; i <= n; ++i)
        {
            bfs(i);
        }
        ans = 1e9;
        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}