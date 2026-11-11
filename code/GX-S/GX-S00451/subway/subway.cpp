#include <bits/stdc++.h>
#define ll long long
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
ll read()
{
    ll i = 0, s = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-') c = getchar();
    if(c == '-') s = -1, c = getchar();
    while(c >= '0' && c <= '9') i = i * 10 + c - '0', c = getchar();
    return i * s;
}
const int N = 505, V = 5e5 + 5, D = 25;
int C, n, m, d, k[N], q, s[V][D], sc[V];
ll f[N][N], ew[V], subt[V][D];
inline void add(int subway, int sta, ll wt)
{
    // printf("add(sub=%d, station=%d, waiting time=%lld)\n", subway, sta, wt);
    s[sta][++sc[sta]] = subway;
    subt[sta][sc[sta]] = wt;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(f, 0x3f, sizeof(f));
    C = read(), n = read(), m = read(), d = read(), q = read();
    for(int x = 1; x <= m; ++x) ew[x] = read();
    for(int x = 1; x <= n; ++x)
    {
        k[x] = read();
        int a, t;
        for(int y = 1; y <= k[x]; ++y)
            a = read(), t = read(), add(x, a, t);
    }
    for(int x = 1; x <= m; ++x)
    {
        // station x    sub[x][y] <-> sub[x][z]
        // printf("x = %d, sc[x] = %d\n", x, sc[x]);
        for(int y = 1; y <= sc[x]; ++y)
        {
            for(int z = y + 1; z <= sc[x]; ++z)
            {
                int su = s[x][y], sv = s[x][z];
                // printf("station %d -> train %d, train %d\n", x, su, sv);
                // printf("f[%d][%d] = %lld\n", su, sv, f[su][sv]);
                f[su][sv] = f[sv][su] = min(f[su][sv], subt[x][y] + subt[x][z]);
                // printf("f[%d][%d] <- %lld\n", su, sv, subt[x][y] + subt[x][z]);
            }
        }
    }
    for(int x = 1; x <= n; ++x) f[x][x] = 0;
    for(int mid = 1; mid <= n; ++mid)
    {
        for(int x = 1; x < mid; ++x)
        {
            for(int y = mid + 1; y <= n; ++y)
            {
                // printf("f[%d][%d] <- min(%lld, %lld)\n", x, y, f[x][y], f[x][mid] + f[mid][y]);
                f[x][y] = min(f[x][y], f[x][mid] + f[mid][y]);
            }
        }
    }
    for(int x = 1; x <= q; ++x)
    {
        int u = read(), v = read();
        // printf("u = %d, v = %d\n", u, v);
        ll ans = 1145141919810114514;
        for(int y = 1; y <= sc[u]; ++y)
        {
            for(int z = 1; z <= sc[v]; ++z)
            {
                int su = s[u][y], sv = s[v][z];
                if(su > sv) swap(su, sv);
                // printf("station u=%d -> subway %d --%lld-> subway %d -> station v=%d\n", u, su, f[su][sv], sv, v);
                ans = min(ans, subt[u][y] + subt[v][z] + f[su][sv]);
            }
        }
        printf("%lld\n", ans + ew[u] + ew[v]);
    }
    return 0;
}