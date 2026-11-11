#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, q, t[500005], vis[500005], ans;

struct node
{
    long long id, t;
};

vector<node> b[500005];
vector<node> a[505];

void dfs(long long x, long long y, long long fa, long long cnt)
{
    vis[x] = cnt;
    if (x == y)
    {
        ans = min(ans, cnt);
        return ;
    }
    for (int i=0; i<int(b[x].size()); i++)
    {
        if (b[x][i].id == fa)
        {
            continue;
        }
        for (int j=1; j<int(a[b[x][i].id].size()); j++)
        {
            if (vis[a[b[x][i].id][j].id] < cnt+b[x][i].t+a[b[x][i].id][j].t || a[b[x][i].id][j].id == x)
            {
                continue;
            }
            dfs(a[b[x][i].id][j].id, y, b[x][i].id, cnt+b[x][i].t+a[b[x][i].id][j].t);
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i=1; i<=m; i++)
    {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++)
    {
        long long x;
        cin >> x;
        a[i].push_back({x, 0});
        for (int j=1; j<=x; j++)
        {
            long long y, z;
            cin >> y >> z;
            a[i].push_back({y, z});
            b[y].push_back({i, z});
        }
    }
    while (q--)
    {
        ans = 1e8;
        for (int i=1; i<=m; i++)
        {
            vis[i] = 1e8;
        }
        long long x, y;
        cin >> x >> y;
        dfs(x, y, 0, t[x]+t[y]);
        cout << ans << endl;
    }
    return 0;
}
