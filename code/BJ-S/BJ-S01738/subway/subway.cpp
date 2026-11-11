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

int c, n, m, d, q;

int w[500010];

int k[510];

vector <int> a[510], t[510];

vector <pair <int, int> > p[500010];//the station is pass by these lines

int dis[510][510];

vector <int> f[500010];

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1;i <= m;i++)w[i] = read();
    for(int i = 1;i <= n;i++)
    {
        k[i] = read();
        for(int j = 1;j <= k[i];j++)
        {
            int x = read(), y = read();
            a[i].push_back(x), t[i].push_back(y);
            p[x].push_back(make_pair(i, y));
        }
    }
    for(int i = 1;i <= n;i++)for(int j = 1;j <= n;j++)dis[i][j] = 4000000000000000000ll;
    for(int i = 1;i <= n;i++)dis[i][i] = 0;
    for(int i = 1;i <= m;i++)
    {
        for(int j = 0;j < p[i].size();j++)
        {
            for(int k = j + 1;k < p[i].size();k++)
            {
                int u = p[i][j].first, v = p[i][k].first, w = p[i][j].second + p[i][k].second;
                dis[u][v] = dis[v][u] = min(dis[u][v], w);
            }
        }
    }
    for(int k = 1;k <= n;k++)for(int i = 1;i <= n;i++)for(int j = i + 1;j <= n;j++)dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while(q--)
    {
        int x = read(), y = read();
        int ans = 4000000000000000000ll;
        for(int i = 0;i < p[x].size();i++)
        {
            for(int j = 0;j < p[y].size();j++)
            {
                ans = min(ans, w[x] + w[y] + p[x][i].second + p[y][j].second + dis[p[x][i].first][p[y][j].first]);
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}