#include<bits/stdc++.h>
using namespace std;

const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, w[M], len[M];
long long dis[N][N];
struct node
{
    int v, w;
};
vector<node> t[M];


int read()
{
    int w = 1, x = 0; char ch;
    ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') w *= -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * w;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            dis[i][j] = 1e18;
        dis[i][i] = 0;
    }
    dis[0][0] = 1e18;
    c = read(); n = read(); m = read(); d = read(); q = read();
    for(int i = 1; i <= m; i++)
        w[i] = read();
    for(int i = 1; i <= n; i++)
    {
        long long k, a, tt;
        k = read();
        for(int j = 1; j <= k; j++)
        {
            a = read(); tt = read();
            for(int l = 0; l < len[a]; l++)
            {
                int v = t[a][l].v; int ww = t[a][l].w;
                dis[i][v] = min(dis[i][v], tt + ww);
                dis[v][i] = dis[i][v];
            }
            t[a].push_back({i, tt});
            len[a]++;
        }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int x, y;
    for(int i = 1; i <= q; i++)
    {
        x = read(); y = read();
        long long ans = 1e18;
        for(int j = 0; j < len[x]; j++)
        {
            int u = t[x][j].v;
            for(int l = 0; l < len[y]; l++)
            {
                int v = t[y][l].v;
                ans = min(ans, 1ll * t[x][j].w + dis[u][v] + 1ll * t[y][l].w);
            }
        }
        ans += w[x] + w[y];
        printf("%lld\n", ans);
    }
    return 0;
}
