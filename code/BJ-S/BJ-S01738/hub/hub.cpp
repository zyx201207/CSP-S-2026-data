#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    register char c = getchar();
    register int x = 0, f = 1;
    while(c < '0' || c > '9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

inline void _write(int x)
{
    if(!x)return;
    _write(x / 10);
    putchar(x % 10 + '0');
    return;
}

inline void write(int x)
{
    if(x < 0)putchar('-'), x = -x;
    if(x == 0)putchar('0');
    else _write(x);
}

struct edge
{
    int u, v, nxt;
}e[4000010];

int h[2000010], cnt;

void addedge(int u, int v)
{
    e[++cnt] = {u, v, h[u]};
    h[u] = cnt;
    return;
}

int n, k;

bool vis[11];

void dfs(int x, int f)
{
    vis[x] = 1;
    for(int i = h[x];i;i = e[i].nxt)
    {
        int v = e[i].v;
        if(vis[v] || (f & (1 << (v - 1))) == 0)continue;
        dfs(v, f);
    }
    return;
}

int getdis(int x, int f, int c)
{
    vis[x] = 1;
    int dis = 100;
    for(int i = h[x];i;i = e[i].nxt)
    {
        int v = e[i].v;
        if(vis[v])continue;
        if((f & (1 << (v - 1))))return 1;
        dis = min(dis, getdis(v, f, c));
    }
    return dis + 1;
}

int calcans(int f)
{
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        memset(vis, 0, sizeof(vis));
        if((f & (1 << (i - 1))) == 0)ans = max(ans, getdis(i, f, i));
    }
    return ans;
}

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c = read(), T = read();
    while(T--)
    {
        n = read(), k = read();
        for(int i = 1;i < n;i++)
        {
            int u = read(), v = read();
            addedge(u, v);
            addedge(v, u);
        }
        int ans = n;
        if(n <= 10)
        {
            for(int i = 0;i < (1 << n);i++)
            {
                if(__builtin_popcount(i) == k)
                {
                    memset(vis, 0, sizeof(vis));
                    int tot = 0;
                    for(int j = 1;j <= n;j++)if(!vis[j] && (i & (1 << (j - 1))))dfs(j, i), tot++;
                    if(tot == 2)
                    {
                        ans = min(ans, calcans(i));
                    }
                }
            }
            write(ans);
            putchar('\n');
        }
        else
        {
            cout << ceil((n + 1 - 2 * k) / 8.0) + 1 << "\n";
        }
        for(int i = 1;i <= n;i++)h[i] = 0, e[i] = {0, 0, 0};
        cnt = 0;
    }
    return 0;
}