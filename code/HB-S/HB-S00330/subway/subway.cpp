#include <bits/stdc++.h>
using namespace std;
#define N 505
#define M 130005
int c, n, m, d, q;
struct line
{
    int cnts = 0;
    bool s[50005];
} l[N];
struct station
{
    int cntl = 0, w; //line sum, floor -> lobby
    int t[25]; //lobby -> stop
    long long l; //line
} s[M];
int Dis(int x, int y)
{
    int lx = 0, ly = 0;
    while (s[x].l)
    {
        s[x].l >>= 1;
        lx++;
    }
    while (s[y].l)
    {
        s[y].l >>= 1;
        ly++;
    }
    int res = 0;
    res = res + s[x].w + s[y].w;
    res = res + s[x].t[lx] + s[y].t[ly];
    if (s[x].l && s[y].l != 0)
    {
        int k = s[x].l && s[y].l, di = 0;
        while (k)
        {
            k >>= 1;
            di++;
        }
        res += s[di].t[lx] + s[di].t[ly];
    }
    return res;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &s[i].w);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &l[i].cnts);
        for (int j = 1; j <= l[i].cnts; j++)
        {
            int a;
            scanf("%d%d", &a, &s[a].t[i]);
            s[a].l = (s[a].l & (1 << (i - 1)));
            l[i].s[a] = true;
            s[i].cntl++;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int s, e; //start, end
        scanf("%d%d", &s, &e);
        printf("%d", Dis(s, e));
    }
    return 0;
}
