#include <bits/stdc++.h>

using namespace std;

const long long maxn = 5e5 + 510, maxq = 1e5 + 10;

struct edge
{
    long long v, w;
};

struct node
{
    long long u, d;
    friend bool operator < (node x, node y)
    {
        return x.d > y.d;
    }
};

struct query
{
    long long id, x, y, ans;
} qs[maxq];

bool cmp_x(query a, query b)
{
    return a.x < b.x;
}

bool cmp_id(query a, query b)
{
    return a.id < b.id;
}

vector<edge> V[maxn];
long long c, n, m, d, q;
long long w[510];

bool book[maxn];
long long dis[maxn];
priority_queue<node> Q;

void dijkstra(long long s)
{
    long long i;
    memset(book, 0, sizeof book);
    memset(dis, 0x7f, sizeof dis);
    dis[s] = 0;
    Q.push({s, 0});
    while (!Q.empty())
    {
        node node_u = Q.top();
        long long u = node_u.u;
        book[u] = 1;
        Q.pop();
        for (auto edge_v : V[u])
        {
            long long v = edge_v.v;
            long long w = edge_v.w;
            if (book[v]) continue;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                //if(v==4)cout<<'!'<<u<<v<<dis[u]<<dis[v]<<w<<'!';
                Q.push({v, dis[v]});
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long i, j;

    cin >> c >> n >> m >> d >> q;
    for (i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (i = 1; i <= n; i++)
    {
        long long ki;
        cin >> ki;
        for (j = 1; j <= ki; j++)
        {
            long long aij, tij;
            cin >> aij >> tij;
            V[aij + n].push_back({i, tij});
            V[i].push_back({aij + n, tij});
            //if(j==1&&aij==2)cout<<tij<<endl;
        }
    }
    for (i = 1; i <= q; i++)
    {
        long long xx, yy;
        cin >> xx >> yy;
        qs[i] = {i, xx, yy, 0};
    }

    sort(qs + 1, qs + q + 1, cmp_x);
    long long last = 0;
    for (i = 1; i <= q; i++)
    {
        if (last != qs[i].x)
        {
            dijkstra(qs[i].x + n);
            last = qs[i].x;
        }
        qs[i].ans = dis[qs[i].y + n] + w[qs[i].x] + w[qs[i].y];
    }

    sort(qs + 1, qs + q + 1, cmp_id);
    for (i = 1; i <= q; i++)
    {
        cout << qs[i].ans << '\n';
    }

    return 0;
}
