#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pb push_back
#define mkp make_pair
#define fst first
#define sed second
#define gc getchar
typedef long long ll;
const int N = 5e5 + 10, M = 510;
int w[N], c, n, m, d, q;
vector<pair<int, int> >idx[N];
ll dp[M][M];
il void addedge(int u, int v, ll w)
{
    dp[u][v] = min(dp[u][v], w);
    dp[v][u] = min(dp[v][u], w);
}
il int read()
{
    char ch = 0;
    while(ch < 48 || ch > 57) ch = gc();
    int x = 0;
    while(48 <= ch && ch <= 57)
    {
        x = (x << 1) + (x << 3) + ch - 48;
        ch = gc();
    }
    return x;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1;i <= m;++i) w[i] = read();
    for(int i = 1;i <= n;++i)
    {
        int k = read();
        while(k--)
        {
            int x = read(), y = read();
            idx[x].pb(mkp(i, y));
        }
    }
    memset(dp, 0x3f, sizeof dp);
    for(int i = 1;i <= n;++i) dp[i][i] = 0;
    for(int i = 1;i <= m;++i)
    {
        for(int ii = 0;ii < idx[i].size();++ii)
        {
            for(int jj = ii + 1;jj < idx[i].size();++jj)
            {
                if(idx[i][ii].fst == idx[i][jj].fst) continue;
                addedge(idx[i][ii].fst, idx[i][jj].fst, idx[i][ii].sed + idx[i][jj].sed);
            }
        }
    }
    for(int k = 1;k <= n;++k)
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= n;++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    while(q--)
    {
        int x = read(), y = read();
        ll ans = 1e18;
        for(auto ii : idx[x])
            for(auto jj : idx[y])
                ans = min(ans, ii.sed + jj.sed + dp[ii.fst][jj.fst]);
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}
