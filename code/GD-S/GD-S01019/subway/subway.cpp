#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#define MAXN 503
#define MAXM 500003
using namespace std;
using lli = long long;

namespace IO
{
#define SIZ (1 << 18)
    static char ibuf[SIZ], *p1 = nullptr, *p2 = nullptr;
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZ, stdin), p1 == p2) ? EOF : *p1++)
    void rd(int &x)
    {
        x = 0;
        char c = gc();
        while (!isdigit(c))
            c = gc();
        while (isdigit(c))
            x = x * 10 + (c ^ 48), c = gc();
    }
    template <typename... Arg>
    inline void rd(int &x, Arg &...args)
    {
        rd(x), rd(args...);
    }
    static char obuf[SIZ], *p3 = obuf;
    inline void flush()
    {
        fwrite(obuf, 1, exchange(p3, obuf) - obuf, stdout);
    }
    inline void pc(const char c)
    {
        if (p3 - obuf == SIZ)
            flush();
        *p3++ = c;
    }
    void prt(lli x)
    {
        static char stk[21];
        int stkp = 0;
        do
        {
            stk[stkp++] = (char)(x % 10 + '0'), x /= 10;
        } while (x);
        while (stkp)
            pc(stk[--stkp]);
        pc('\n');
    }
#undef gc
#undef SIZ
}
using IO::prt;
using IO::rd;

vector<pair<int, int>> g[MAXM];
int a[MAXM];
lli dis[MAXN][MAXN];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int n, m, q;
    rd(n, n, m, q, q);
    for (int i = 1; i <= m; ++i)
        rd(a[i]);
    for (int i = 1, ki; i <= n; ++i)
    {
        rd(ki);
        while (ki--)
        {
            int id, val;
            rd(id, val);
            g[id].emplace_back(i, val);
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; ++i)
        for (const pair<int, int> &e1 : g[i])
            for (const pair<int, int> &e2 : g[i])
                dis[e1.first][e2.first] = min(dis[e1.first][e2.first], (lli)e1.second + e2.second);
    for (int i = 1; i <= n; ++i)
        dis[i][i] = 0;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--)
    {
        int x, y;
        long long ans = 0x3f3f3f3f3f3f3f3fLL;
        rd(x, y);
        for (const pair<int, int> &e1 : g[x])
            for (const pair<int, int> &e2 : g[y])
                ans = min(ans, dis[e1.first][e2.first] + e1.second + e2.second);
        prt(ans + a[x] + a[y]);
    }
    IO::flush();
    return 0;
}
