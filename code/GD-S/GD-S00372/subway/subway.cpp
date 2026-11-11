#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,ll>
#define fi first
#define se second
#define pb emplace_back
using namespace std;
const int N = 510, M = 500010;
int c, n, m, d, q;
ll w[M];
ll dis[N][N];
vector<pa>e[M];
void ma(ll &x, ll y)
{
    x = min(x, y);
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dis, 0x3f, sizeof dis);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++)scanf("%lld", w + i);
    for(int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
        int k;
        scanf("%d", &k);
        while(k--)
        {
            int a, t;
            scanf("%d%d", &a, &t);
            e[a].pb(i, t);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j < e[i].size(); j++)
            for(int k = 0; k < e[i].size(); k++)
                ma(dis[e[i][j].fi][e[i][k].fi], e[i][j].se + e[i][k].se);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
    while(q--)
    {
        int x, y;
        ll ans = 1e18;
        scanf("%d%d", &x, &y);
        for(pa tx : e[x])
            for(pa ty : e[y])
                ans = min(ans, tx.se + ty.se + dis[tx.fi][ty.fi]);
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}
