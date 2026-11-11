#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// #define int LL
#define For(i, t, n) for (int i = t; i <= n; ++i)
#define foR(i, t, n) for (int i = t; i >= n; --i)
#define isdigit(c) (c >= 48 && c <= 57)
#define gc getchar
void read(int &x)
{
    x = 0;
    int c = gc(), f = 1;
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = gc();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = gc();
    }
    x *= f;
}
void write(int x)
{
    int stk[100], top = 0;
    if (x < 0)
        putchar('-'), x = -x;
    do
    {
        stk[++top] = x % 10;
        x /= 10;
    } while (x);
    while (top)
        putchar(stk[top--] | 48);
}
const int MAXN = 1e6 + 5;

int n, k, id;
vector<int> G[MAXN];

void solve()
{
    read(n);
    read(k);
    For(i, 1, n - 1)
    {
        int u, v;
        read(u), read(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    write(++id);
    putchar('\n');
    For(i, 1, n) G[i].clear();
}

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    read(c);
    read(t);
    while (t--)
        solve();
    return 0;
}
