#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 5e5 + 5, L = 505;
long long dis[L][L];
int cost[N][L], c, n, m, d, q, cat[N][L], cnt[N], k, wi[N], x, y, t;

int main()
{
    freopen("subway6.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i ++)
        scanf("%d", &wi[i]);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", &k);
        for(int j = 1; j <= k; j ++)
        {
            scanf("%d %d", &x, &t);
            cost[x][i] = t;
            cat[x][++ cnt[x]] = i;
        }
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            dis[i][j] = 5e17;
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= cnt[i]; j ++)
            for(int k = j + 1; k <= cnt[i]; k ++)
            {
                x = cat[i][j], y = cat[i][k];
                dis[x][y] = dis[y][x] = min(dis[x][y], cost[i][x] * 1ll + cost[i][y]);
            }
    for(int i = 1; i <= n; i ++)
        dis[i][i] = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            for(int k = 1; k <= n; k ++)
                if(dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
    while(q --)
    {
        scanf("%d %d", &x, &y);
        long long ans = 2e18;
        for(int j = 1; j <= cnt[x]; j ++)
            for(int k = 1; k <= cnt[y]; k ++)
            {
                int a = cat[x][j], b = cat[y][k];
                ans = min(ans, dis[a][b] + cost[x][a] + cost[y][b]);
            }
        printf("%lld\n", ans + wi[x] + wi[y]);
    }
}
