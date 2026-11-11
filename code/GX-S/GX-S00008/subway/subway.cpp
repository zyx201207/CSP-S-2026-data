#include <bits/stdc++.h>
#define sint static int
#define cint const int
#define ll long long
#define sll static ll
#define cll const ll
#define pil pair<int, ll>
#define isd(x) ((x) >= '0' && (x) <= '9')
#define rep(_, start, stop) for (int _ = (start); _ <= (stop); ++_)
using namespace std; constexpr int N = 500, M = 5.1e5; constexpr ll INF = 1e18;
sint c, n, m, d, q, len[M + 5]; sll w[M + 5], fin[N + 5][N + 5]; static pil belong[M + 5][21];
sll read()
{
    ll res = 0; int c = getchar(); while (!isd(c)) { c = getchar(); }
    while (isd(c)) { res = (res << 1) + (res << 3) + c - '0'; c = getchar(); } return res;
}
void write(cll x) { if (x >= 10) { write(x / 10); } putchar(x % 10 + '0'); }
int main()
{
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    c = read(); n = read(); m = read(); d = read(); q = read() + 1; rep(i, 1, m) { w[i] = read(); }
    rep(i, 1, n)
    { cint k = read(); rep(j, 1, k) { cint a = read(); cll t = read(); belong[a][++len[a]] = {i, t}; } }
    rep(i, 1, n) { rep(j, 1, n) { fin[i][j] = i == j ? 0 : INF; } }
    rep(i, 1, m)
    {
        rep(j, 1, len[i])
        {
            cint u = belong[i][j].first; cll k1 = belong[i][j].second;
            rep(l, 1, len[i])
            {
                cint v = belong[i][l].first; cll k2 = belong[i][l].second;
                fin[u][v] = fin[v][u] = min(fin[u][v], k1 + k2);
            }
        }
    }
    rep(k, 1, n) { rep(i, 1, n) { rep(j, 1, n) { fin[i][j] = min(fin[i][j], fin[i][k] + fin[k][j]); } } }
    while (--q)
    {
        cint x = read(), y = read(); ll ans = INF;
        rep(i, 1, len[x])
        {
            cint u = belong[x][i].first; cll k = belong[x][i].second;
            rep(j, 1, len[y])
            { cint v = belong[y][j].first; cll l = belong[y][j].second; ans = min(ans, fin[u][v] + k + l); }
        } write(ans + w[x] + w[y]); putchar('\n');
    }
    return 0;
}
