#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 500, M = 500000;
int w[M], head[M], e[M], next[M], t1[M], idx, start[N + 1], place[M], t2[M];
long long dis[N][N];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(head, -1, sizeof head);
    memset(dis, 0x3f, sizeof dis);
    int n, m, q;
    scanf("%*s%d%d%*s%d", &n, &m, &q);
    for (int i = 0; i < m; ++i)
        scanf("%d", w + i);
    for (int i = 0; i < n; ++i)
    {
        dis[i][i] = 0;
        int k;
        scanf("%d", &k);
        start[i] = idx;
        for (int j = 0; j < k; ++j)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            --a;
            t1[idx] = b, e[idx] = i, next[idx] = head[a], head[a] = idx;
            place[idx] = a, t2[idx++] = b;
        }
    }
    start[n] = idx;
    for (int i = 0; i < n; ++i)
        for (int x = start[i]; x < start[i + 1]; ++x)
            for (int j = head[place[x]]; ~j; j = next[j])
                dis[i][e[j]] = dis[e[j]][i] = std::min(dis[i][e[j]], (long long)t2[x] + t1[j]);
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        long long ans = 0x3f3f3f3f3f3f3f3fLL;
        for (int i = head[x]; ~i; i = next[i])
            for (int j = head[y]; ~j; j = next[j])
                ans = std::min(ans, dis[e[i]][e[j]] + t1[i] + t1[j]);
        printf("%lld\n", ans + w[x] + w[y]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
