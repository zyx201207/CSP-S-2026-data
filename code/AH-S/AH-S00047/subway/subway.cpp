#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, LL> PIL;

const int N = 510, M = 5e5 + 10, D = 25;
const LL INF = 1e18;

int c, n, m, d, q;
int w[M];
PIL edges[M][D];
int cnt[M];
LL dist[N][N];

int read()
{
    int num = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <='9')
    {
        num = (num << 1) + (num << 3) + (ch ^ 48);
        ch = getchar_unlocked();
    }
    return num;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i ++ )
        w[i] = read();

    for (int i = 1; i <= n; i ++ )
    {
        int k;
        k = read();
        for (int j = 1; j <= k; j ++ )
        {
            int a;
            LL t;
            a = read(), t = read();
            cnt[a] ++ ;
            edges[a][cnt[a]] = {i, t};
        }
    }

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            dist[i][j] = INF;
            if (i == j) dist[i][j] = 0;
        }


    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= cnt[i]; j ++ )
            for (int k = j + 1; k <= cnt[i]; k ++ )
            {
                int x1 = edges[i][j].first, x2 = edges[i][k].first;
                LL y1 = edges[i][j].second, y2 = edges[i][k].second;
                dist[x1][x2] = dist[x2][x1] = min(dist[x1][x2], y1 + y2);
            }

    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    while (q -- )
    {
        int x, y;
        x = read(), y = read();

        LL res = INF;
        for (int i = 1; i <= cnt[x]; i ++ )
            for (int j = 1; j <= cnt[y]; j ++ )
            {
                int v1 = edges[x][i].first, v2 = edges[y][j].first;
                LL e1 = edges[x][i].second, e2 = edges[y][j].second;
                res = min(res, e1 + e2 + dist[v1][v2]);
            }
        printf("%lld\n", res + w[x] + w[y]);
    }

    return 0;
}
