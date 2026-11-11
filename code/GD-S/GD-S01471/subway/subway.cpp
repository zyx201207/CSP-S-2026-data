#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL
#define For(i, t, n) for (signed i = t; i <= n; ++i)
#define foR(i, t, n) for (signed i = t; i >= n; --i)
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
const int MAXN = 5e5 + 5;
const int MAXM = 1e3 + 5;

int c, n, m, d, q;
int w[MAXN], l[505];
#define fi first
#define se second

int dis[MAXM][MAXM];
int a[MAXM][MAXM];
int t[MAXM][MAXM];
bitset<MAXM> vis;
vector<pair<int, int>> G[MAXN];
struct node
{
    int u, d;
    bool operator<(const node &b) const
    {
        return d > b.d;
    }
};
void dij(int st)
{
    dis[st][st] = 0;
    vis.reset();
    // vis[st] = 1;
    priority_queue<node> q;
    q.push({st, 0});
    while (q.size())
    {
        node t = q.top();
        q.pop();
        if (vis[t.u])
            continue;
        vis[t.u] = 1;
        for (auto [v, w] : G[t.u])
        {
            if (vis[v])
                continue;
            // cerr << dis[st][t.u] + w << " >> "<<dis[st][v]<<"\n";
            if (dis[st][t.u] + w < dis[st][v])
            {
                dis[st][v] = dis[st][t.u] + w;
                q.push({v, dis[st][v]});
            }
        }
    }
}

void task1()
{
    memset(dis, 0x3f, sizeof dis);
    For(i, 1, n)
    {
        read(l[i]);
        For(j, 1, l[i])
        {
            // int a, t;
            read(a[i][j]);
            // v[i][a[i][j]] = 1;
            read(t[i][a[i][j]]);
        }
    }
    For(k, 1, n)
        For(i, 1, l[k])
    {
        For(j, i + 1, l[k])
        {
            int u = a[k][i], v = a[k][j];
            dis[u][v] = dis[v][u] = min(dis[u][v], t[k][u] + t[k][v]);
            G[u].push_back({v, dis[u][v]});
            G[v].push_back({u, dis[u][v]});
        }
    }
    // For(i,1,m){
    //     For(j,1,m){
    //         if(dis[i][j]<2e18)
    //             G[i].push_back({j,dis[i][j]}),
    //                 G[j].push_back({i,dis[i][j]});
    //     }
    // }
    memset(dis, 0x3f, sizeof dis);
    // For(i, 1, m) dis[i][i] = 0;
    // For(i, 1, m)
    // {
    //     cerr << G[i].size() << '\n';
    //     for (auto [v, w] : G[i])
    //         cerr << v << "(" << w << ") ";
    //     cerr << '\n';
    // }
    // For(k, 1, m)
    // {
    //     For(i, 1, m)
    //     {
    //         if (i == k)
    //             continue;
    //         For(j, 1, m)
    //         {
    //             if (k == j || i == j)
    //                 continue;
    //             dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    //         }
    //     }
    // }
    For(i, 1, m) dij(i);
    while (q--)
    {
        int x, y;
        read(x);
        read(y);
        write(w[x] + w[y] + dis[x][y]);
        putchar('\n');
    }
}

void solve()
{
    read(c), read(n), read(m), read(d), read(q);
    For(i, 1, m) read(w[i]);
    // if (c <= 11)
        task1();
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    // freopen("s2.err", "w", stderr);
    solve();
    return 0;
}
