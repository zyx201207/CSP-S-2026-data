#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 505;
const int M = 5e5 + 5;

int c, n, m, d, q, k[N];
ll w[M];
vector<int> a[N];
vector<ll> t[N];
vector<pair<int, int>> fa[M];
ll f[N][N];
// n:共有n条线路
// m:共有m个站(厅)
// a[i]:第i号线经过哪些站(厅)
// t[i]:第i号线的站厅到各个站台的时间
// fa[i]:第i号站厅属于哪号线路  哪些线路经过第i站

void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    return;
}

ll get(int x, int y)
{
    ll res = 1e18;
    for (int i = 0; i < fa[x].size(); ++i)
    {
        for (int j = 0; j < fa[y].size(); ++j)
        {
            res = min(res, t[fa[x][i].first][fa[x][i].second] + t[fa[y][j].first][fa[y][j].second] + f[fa[x][i].first][fa[y][j].first]);
        }
    }
    return res;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
        for (int j = 0, x; j < k[i]; ++j)
        {
            cin >> x;
            a[i].push_back(x);
            fa[x].emplace_back(i, j); // 第x站是第i号线路的第j站
            cin >> x;
            t[i].push_back(x);
        }
    }

    //check fa   ok
    // for (int i = 1; i <= m; ++i)
    // {
    //     for (auto [x, y] : fa[i])
    //         cout << '(' << x << ',' << y << ")  ";
    //     cout << '\n';
    // }



    //重构图，连边，初始化f数组
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            f[i][j] = 1e18;
    for (int i = 1; i <= n; ++i) f[i][i] = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int i1 = 0; i1 < fa[i].size(); ++i1)
        {
            for (int i2 = 0; i2 < i1; ++i2)
            {
                int u = fa[i][i1].first;
                int v = fa[i][i2].first;
                f[u][v] = f[v][u] = min(f[u][v], t[u][fa[i][i1].second] + t[v][fa[i][i2].second]); // transform fee
            }
        }
    }

    // for (int i = 1; i <= m; ++i)
    // {
    //     for (int j = 1; j < fa[i].size(); ++j)
    //     {
    //         int x = fa[i][j].first;
    //         int y = fa[i][j].second;
    //         if (t[x][y] < t[fa[i][0].first][fa[i][0].second])
    //             swap(fa[i][0], fa[i][j]);
    //     }
    // }


    floyd();

    //check f   ok
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    //not yet --- the answer should be added w and t
    for (int i = 1, x, y; i <= q; ++i)
    {
        cin >> x >> y;
        // cout << fa[x][0].first << ' ' << fa[x][0].second << ' ' << fa[y][0].first << ' ' << fa[y][0].second << '\n';
        // cout << t[fa[x][0].first][fa[x][0].second] << ' ' << t[fa[y][0].first][fa[y][0].second] << '\n';
        // cout << t[fa[x][0].first][fa[x][0].second] + t[fa[y][0].first][fa[y][0].second] + f[fa[x][0].first][fa[y][0].first] << '\n';
        cout << w[x] + w[y] + get(x, y) << '\n';
    }
    return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
