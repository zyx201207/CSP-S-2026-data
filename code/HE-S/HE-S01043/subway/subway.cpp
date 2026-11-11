#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <utility>
#include <vector>
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

const int NR = 510;
const int MR = 5e5 + 10;
long long w[MR];
long long dis[NR][NR];
vector<pair<int, int>> buc[MR];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int tcase = read();
    int n = read(), m = read(), tdeg = read(), Q = read();
    for (int i = 1; i <= m; i ++)
    {
        w[i] = read();
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        int k = read();
        while (k --)
        {
            int a = read(), t = read();
            buc[a].push_back(make_pair(i, t));
        }
    }
    for (int i = 1; i <= m; i ++)
    {
        for (int j1 = 0; j1 < (int)buc[i].size(); j1 ++)
        {
            for (int j2 = j1 + 1; j2 < (int)buc[i].size(); j2 ++)
            {
                int u1 = buc[i][j1].first, u2 = buc[i][j2].first;
                long long v1 = buc[i][j1].second, v2 = buc[i][j2].second;
                dis[u1][u2] = min(dis[u1][u2], v1 + v2);
                dis[u2][u1] = min(dis[u2][u1], v2 + v1);
            }
        }
    }
    for (int k = 1; k <= n; k ++)
    {
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= n; j ++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (Q --)
    {
        int x = read(), y = read();
        long long ans = 1e18;
        for (int j1 = 0; j1 < (int)buc[x].size(); j1 ++)
        {
            for (int j2 = 0; j2 < (int)buc[y].size(); j2 ++)
            {
                int u1 = buc[x][j1].first, u2 = buc[y][j2].first;
                long long v1 = buc[x][j1].second, v2 = buc[y][j2].second;
                ans = min(ans, w[x] + v1 + dis[u1][u2] + v2 + w[y]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}