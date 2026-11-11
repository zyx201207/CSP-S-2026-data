#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

inline int read()
{
    int f = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return f * x;
}

const int NR = 1e6 + 10;
int a[NR];

struct edge
{
    int nxt, to;
} e[NR * 2];

int head[NR], mtot;

void add(int x, int y)
{
    e[++mtot] = (edge){head[x], y};
    head[x] = mtot;
}

int vis[NR];

void dfs(int x)
{
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = e[i].nxt)
    {
        int y = e[i].to;
        if (!a[y] || vis[y]) continue;
        dfs(y);
    }
}

int dis[NR];
queue<int> q;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int tcase = read(), T = read();
    while (T --)
    {
        int n = read(), k = read();
        memset(head, -1, sizeof(int) * (n + 5));
        mtot = 0;
        for (int i = 1; i < n; i ++)
        {
            int x = read(), y = read();
            add(x, y);
            add(y, x);
        }
        int ans = 1e9;
        for (int S = 0; S < (1 << n); S ++)
        {
            int num = 0;
            for (int i = 1; i <= n; i ++)
            {
                if ((S >> (i - 1)) & 1)
                {
                    a[i] = 1;
                    num ++;
                }
                else a[i] = 0;
            }
            if (num != k) continue;
            memset(vis, 0, sizeof(int) * (n + 5));
            int cnt = 0;
            for (int i = 1; i <= n; i ++)
            {
                if (a[i] && vis[i] == 0)
                {
                    //printf("i = %d\n", i);
                    cnt ++;
                    if (cnt > 2) break;
                    dfs(i);
                }
            }
            //cout << cnt << endl;
            if (cnt > 2) continue;
            while (!q.empty()) q.pop();
            memset(dis, 0x3f, sizeof(int) * (n + 5));
            memset(vis, 0, sizeof(int) * (n + 5));
            for (int i = 1; i <= n; i ++)
            {
                if (a[i])
                {
                    dis[i] = 0;
                    q.push(i);
                    vis[i] = 1;
                    //cout << i << " ";
                }
            }
            int now = 0;
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                now = max(now, dis[x]);
                for (int i = head[x]; i != -1; i = e[i].nxt)
                {
                    int y = e[i].to;
                    if (vis[y]) continue;
                    if (dis[y] > dis[x] + 1)
                    {
                        dis[y] = dis[x] + 1;
                        q.push(y);
                        vis[y] = 1;
                    }
                }
            }
            //printf("now = %d\n", now);
            ans = min(ans, now);
        }
        printf("%d\n", ans);
    }
    return 0;
}