#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define gc getchar
inline int rd()
{
    int x = 0, f = 1;
    char c = gc();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = gc();
    }
    while (isdigit(c))
        x = x * 10 + c - '0', c = gc();
    return x * f;
}

const int N = 510, M = 500010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;
int w[M];
vector<int> l[M], t[M];
ll dis[N][N];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
    for (int i = 1; i <= m; i++)
        w[i] = rd();
    int k, x, y, s1, s2;
    for (int i = 1; i <= n; i++)
    {
        k = rd();
        for (int j = 0; j < k; j++)
        {
            x = rd(), y = rd();
            l[x].push_back(i);
            t[x].push_back(y);
        }
        for (int j = 1; j <= n; j++)
            dis[i][j] = (i != j) * inf;
    }
    for (int i = 1; i <= m; i++)
    {
        s1 = l[i].size();
        for (int j = 0; j < s1; j++)
            for (int p = j + 1; p < s1; p++)
                dis[l[i][p]][l[i][j]] = dis[l[i][j]][l[i][p]] = min(dis[l[i][j]][l[i][p]], (ll)t[i][j] + t[i][p]);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i][k] != inf && dis[k][j] != inf)
                    dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
    ll ans;
    while (q--)
    {
        x = rd(), y = rd();
        ans = inf;
        s1 = l[x].size(), s2 = l[y].size();
        for (int i = 0; i < s1; i++)
        {
            for (int j = 0; j < s2; j++)
            {
                ans = min(ans, dis[l[x][i]][l[y][j]] + t[x][i] + t[y][j]);
                if (ans == 0)
                    break;
            }
            if (ans == 0)
                break;
        }
        ans += w[x] + w[y];
        printf("%lld\n", ans);
    }
    return 0;
}