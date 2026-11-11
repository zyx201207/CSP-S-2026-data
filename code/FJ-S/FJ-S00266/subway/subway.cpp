#include<cstdio>
#include<algorithm>
using namespace std;

int cc, n, m, d, q, w[500005], k, a, t, c[500005], bi[500005][25], bd[500005][25], x, y;
long long f[505][505], ans;

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &cc, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        while(k--)
        {
            scanf("%d%d", &a, &t);
            bi[a][++c[a]] = i;
            bd[a][c[a]] = t;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            f[i][j] = 1e18;
    for(int i = 1; i <= n; i++)
        f[i][i] = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= c[i]; j++)
            for(int k = 1; k <= c[i]; k++)
            {
                int aa = bi[i][j], bb = bi[i][k], cc = bd[i][j] + bd[i][k];
                if(cc < f[aa][bb]) f[aa][bb] = cc;
            }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k] + f[k][j];
    while(q--)
    {
        scanf("%d%d", &x, &y);
        ans = 1e18;
        for(int i = 1; i <= c[x]; i++)
            for(int j = 1; j <= c[y]; j++)
                ans = min(ans, f[bi[x][i]][bi[y][j]] + bd[x][i] + bd[y][j]);
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}
