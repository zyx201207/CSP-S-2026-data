#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 7;
ll c, n, m, d, q, w[N], k[507], bg, ed, ans, p, vis[N], t[N][507];
struct sta{
    ll v, li;
};
vector<ll> a[507], pst[N];
vector<sta> g[N];

ll read()
{
    char c;
    ll x = 0;
    c = getchar();
    while(c >= '0' && c <='9')x *= 10, x += c - '0', c = getchar();
    return x;
}

void dfs(ll x, ll lst)
{
    //printf("now vis %lld, p : %lld, ans : %lld, lst : %lld\n", x, p, ans, lst);
    if(x == ed)
    {
        ans = min(ans, p + t[x][lst]);
        return;
    }
    if(p >= ans)return;
    vis[x] = 1;
    for(ll j = 0; j < g[x].size(); j++)
    {
        ll nxt = g[x][j].v, wy = g[x][j].li;
        if(wy != lst)p += t[x][lst], p += t[x][wy];
        if(vis[nxt])
        {
            if(wy != lst)p -= t[x][lst], p -= t[x][wy];
            continue;
        }
        dfs(nxt, wy);
        if(wy != lst)p -= t[x][lst], p -= t[x][wy];
    }
    vis[x] = 0;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    //scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for(ll i = 1; i <= m; i++)w[i] = read();
    for(ll i = 1; i <= n; i++)
    {
        k[i] = read();
        for(ll j = 0; j < k[i]; j++)
        {
            ll x, y;
            x = read(), y = read();
            a[i].push_back(x), pst[x].push_back(i), t[x][i] = y;
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j < a[i].size(); j++)
        {
            ll x = a[i][j - 1], y = a[i][j];
            sta nw;
            nw.v = y, nw.li = i;
            g[x].push_back(nw);
            nw.v = x;
            g[y].push_back(nw);
        }
    }
    //for(ll i = 1; i <= m; i++)
    //{
    //    printf("%lld : ", i);
    //    for(ll j = 0; j < g[i].size(); j++)printf("(%lld, %lld) ", g[i][j].v, g[i][j].li);
    //    printf("\n");
    //}
    for(ll i = 1; i <= q; i++)
    {
        bg = read(), ed = read();
        ans = 1e18, p = w[bg] + w[ed];
        memset(vis, 0, sizeof(vis));
        dfs(bg, 0);
        printf("%lld", ans);
        if(i < q)printf("\n");
    }
    return 0;
}
