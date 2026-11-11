#include <bits/stdc++.h>
using namespace std;

vector<int> g[1000001];
int n, m, dep[1000001], up[1000001], out[1000001], dp[1000001], h[1000001], rnk[1000001], cnt[1000001], dfn[1000001][2], str[1000001], clk, st[21][1000001];

void init(int x, int fa)
{
    clk++;
    str[clk] = x;
    dfn[x][0] = clk;
    dep[x] = dep[fa] + 1;
    up[x] = fa;
    h[x] = 0;
    for(int i : g[x])
    {
        if(i == fa)
        {
            continue;
        }
        init(i, x);
        h[x] = max(h[x], h[i] + 1);
    }
    dfn[x][1] = clk;
}

bool sub(int x, int p)
{
    return dfn[p][0] <= dfn[x][1] && dfn[p][0] >= dfn[x][0];
}

int merge(int x, int y)
{
    return dep[x] < dep[y] ? x : y;
}

int lca(int x, int y)
{
    if(x == y)
    {
        return x;
    }
    x = dfn[x][0];
    y = dfn[y][0];
    if(x > y)
    {
        swap(x, y);
    }
    x++;
    const int t = __lg(y - x + 1);
    return up[merge(st[t][x], st[t][y])];
}

int dist(int x, int y)
{
    return dep[x] + dep[y] - (dep[lca(x, y)] << 1);
}

int calc2(int x, int y)
{
    int d = 0;
    for(int i = dfn[y][0];i <= dfn[y][1];i++)
    {
        if(!sub(x, str[i]))
        {
            d = max(d, min(dist(str[i], x), dist(str[i], up[y])));
        }
    }
    return d;
}

bool check(int x, int fa, int p, int c, int lim)
{
    if(dp[x] <= lim)
    {
        if(calc2(x, p) <= c)
        {
            return true;
        }
        return false;
    }
    for(int i : g[x])
    {
        if(i == fa)
        {
            continue;
        }
        if(check(i, x, p, c, lim))
        {
            return true;
        }
    }
    return false;
}

bool solve(int x, int fa, int c)
{
    dp[x] = 1;
    int mx = 0, ch = 0, smx = 0;
    for(int i : g[x])
    {
        if(i == fa)
        {
            continue;
        }
        if(h[i] > mx)
        {
            smx = mx;
            ch = i;
            mx = h[i];
        }
        else if(h[i] > smx)
        {
            smx = h[i];
        }
    }
    for(int i : g[x])
    {
        if(i == fa)
        {
            continue;
        }
        out[i] = max(out[x], (i == ch ? smx : mx)) + 1;
        solve(i, x, c);
        if(h[i] >= c)
        {
            dp[x] += dp[i];
        }
    }
    if(out[x] <= c)
    {
        for(int i : g[x])
        {
            if(i == fa || h[i] < c)
            {
                continue;
            }
            if(check(i, x, i, c, m - (dp[x] - dp[i])))
            {
                return true;
            }
        }
    }
    return false;
}

int calc(int x, int y)
{
    int d = 0;
    for(int i = 1;i <= n;i++)
    {
        if(sub(x, i) || sub(y, i))
        {
            continue;
        }
        d = max(d, min(dist(i, x), dist(i, y)));
    }
    return d;
}

bool check(int x)
{
    if(solve(1, 0, x))
    {
        return true;
    }
    for(int i = 1;i <= m;i++)
    {
        cnt[i] = 0;
    }
    for(int i = 1;i <= n;i++)
    {
        if(dp[i] <= m)
        {
            cnt[dp[i]]++;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cnt[i] += cnt[i - 1];
    }
    int num = 0;
    for(int i = 1;i <= n;i++)
    {
        if(dp[i] <= m)
        {
            num++;
            rnk[cnt[dp[i]]] = i;
            cnt[dp[i]]--;
        }
    }
    for(int i = 1;i <= num;i++)
    {
        for(int j = 1;j <= num && dp[rnk[j]] + dp[rnk[i]] <= m;j++)
        {
            const int u = rnk[i], v = rnk[j];
            if(calc(u, v) <= x)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int t;
    scanf("%*d %d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1;i <= n;i++)
        {
            g[i].clear();
        }
        for(int i = 1;i < n;i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        clk = 0;
        init(1, 0);
        for(int i = 1;i <= n;i++)
        {
            st[0][i] = str[i];
        }
        for(int i = 1;(1 << i) <= n;i++)
        {
            for(int j = 1;j + (1 << i) - 1 <= n;j++)
            {
                st[i][j] = merge(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
        int l = 0, r = n, res = n;
        while(l <= r)
        {
            const int mid = (l + r) >> 1;
            if(check(mid))
            {
                r = mid - 1;
                res = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
