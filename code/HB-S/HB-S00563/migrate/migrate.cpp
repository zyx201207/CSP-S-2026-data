#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define gc getchar
template<typename T>
inline T rd()
{
    T x = 0, f = 1;
    char c = gc();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = gc();
    }
    while (isdigit(c))
        x = x * 10 + c - '0', c = gc();
    return x * f;
}

const int N = 2000010, inf = 0x7f7f7f7f;
int n, dis[N];
ll d, x[N], cnt;

bool check(int a, int b)
{
    int c = 0, nx;
    pii h;
    for (int i = a; i <= b; i++)
        dis[i] = inf;
    queue<pii> q;
    q.emplace(a, 0);
    while (q.size())
    {
        h = q.front(), q.pop();
        nx = h.first + 1;
        while (nx <= b && x[nx] - x[h.first] <= d)
        {
            if (dis[nx] >= h.second + 1)
            {
                dis[nx] = h.second + 1;
                if (nx == b)
                    c++;
                else
                    q.emplace(nx, h.second + 1);
            }
            nx++;
        }
    }
    return c == 2;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    ll dif, tt;
    c = rd<int>(), T = rd<int>();
    while (T--)
    {
        n = rd<int>(), d = rd<ll>();
        for (int i = 1; i <= n; i++)
            x[i] = rd<ll>();
        cnt = 0;
        if (n < 4) // no route
            cnt = 0;
        else if (c == 11 || c == 12) // special case
        {
            dif = x[2] - x[1];
            if (d <= dif)
                cnt = 0;
            else
            {
                tt = d / dif;
                tt = tt * 2 - 1;
                if (tt > 0)
                    cnt = max(0ll, n - tt);
            }
        }
        else // brute-force
        {
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++)
                    cnt += check(i, j);
        }
        printf("%lld\n", cnt);
    }
    return 0;
}