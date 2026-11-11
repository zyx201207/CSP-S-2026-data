#include <algorithm>
#include <cctype>
#include <cstdio>
#define MAXN 500003
using namespace std;
using lli = long long;

namespace IO
{
#define SIZ (1 << 18)
    static char ibuf[SIZ], *p1 = nullptr, *p2 = nullptr;
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZ, stdin), p1 == p2) ? EOF : *p1++)
    template <typename T>
    void rd(T &x)
    {
        x = 0;
        T f = 1;
        char c = gc();
        while (!isdigit(c))
        {
            if (c == '-')
                f = -1;
            c = gc();
        }
        while (isdigit(c))
            x = x * 10 + (c ^ 48), c = gc();
        x *= f;
    }
#undef gc
#undef SIZ
}
using IO::rd;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    lli m;
    static lli a[MAXN];
    rd(n), rd(m);
    for (int i = 1; i <= n; ++i)
        rd(a[i]);
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1, j = 0; i <= n; ++i)
    {
        lli ai = a[i], tmp = (i - j) * a[i];
        m += ai;
        while (tmp > m)
            m -= a[++j], tmp -= ai;
        ans = max(ans, i - j);
    }
    printf("%d", ans);
    return 0;
}
