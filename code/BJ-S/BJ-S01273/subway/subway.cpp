#include<bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q, w[500010], k[510], f[510][510], ans[500010][510];
struct node{
    int v, t;
};
vector<node>a[500010];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &k[i]);
        f[i][i] = 0;
        for(int j = 1; j <= k[i]; j++)
        {
            int x, y;
            scanf("%lld%lld", &x, &y);
            a[x].push_back({i, y});
        }
    }
    for(int i = 1; i <= m; i++)
        for(node j : a[i])
            for(node k : a[i])
            {
                if(j.v == k.v) continue;
                f[j.v][k.v] = j.t + k.t;
            }
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            for(int k = j + 1; k <= n; k++) f[i][k] = (f[i][j] + f[j][k] > f[i][k] ? f[i][k] : f[i][j] + f[j][k]);
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) f[j][i] = f[i][j];
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = 1e17;
        for(node g : a[x])
            for(node h : a[y]) ans = (ans > g.t + f[g.v][h.v] + h.t ? g.t + f[g.v][h.v] + h.t : ans);
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}