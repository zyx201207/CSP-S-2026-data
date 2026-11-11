#include <cstdio>
#include <cstring>
#include <vector>
using std::pair;
using std::vector;

#define I 0x3F3F3F3F3F3F3F3FLL
#define M 501
#define N 500001
#define NM 500501
using Ll = long long;
Ll w[N], s[M][M]; // ie syd: ejs syd2 4 floyd sins 500' ok 4 qb
vector<Ll> c[N]; // ie cros: vtx vtx syd1 go
Ll d[N][M]; // ie dst: $ btw syd

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    Ll n, m, q;
    scanf("%*lld%lld%lld%*lld%lld", &m, &n, &q);
    for (Ll i = 1LL; i <= n; ++i)
    {
        scanf("%lld", &w[i]);
    }
    memset(d, I, sizeof(d));
    for (Ll i = 1LL; i <= m; ++i)
    {
        Ll s;
        scanf("%lld", &s);
        while (s--)
        {
            Ll a, t;
            scanf("%lld%lld", &a, &t);
            c[a].emplace_back(i);
            d[a][i] = t;
        }
    }
    memset(s, I, sizeof(s));
    for (Ll i = 1LL; i <= n; ++i)
    {
        for (const Ll j : c[i])
        {
            for (const Ll k : c[i])
            {
                if (j == k)
                {
                    s[j][k] = 0LL;
                    continue;
                }
                if (s[j][k] > d[i][j] + d[i][k])
                {
                    s[j][k] = d[i][j] + d[i][k];
                }
            }
        }
    }
    for (Ll k = 1LL; k <= m; ++k)
    {
        for (Ll i = 1LL; i <= m; ++i)
        {
            for (Ll j = 1LL; j <= m; ++j)
            {
                if (s[i][j] > s[i][k] + s[k][j])
                {
                    s[i][j] = s[i][k] + s[k][j];
                }
            }
        }
    }
    while (q--)
    {
        Ll x, y;
        scanf("%lld%lld", &x, &y);
        Ll r = I;
        for (const Ll i : c[x])
        {
            for (const Ll j : c[y])
            {
                if (r > d[x][i] + d[y][j] + s[i][j])
                {
                    r = d[x][i] + d[y][j] + s[i][j];
                }
            }
        }
        printf("%lld\n", w[x] + w[y] + r);
    }
    return 0;
}