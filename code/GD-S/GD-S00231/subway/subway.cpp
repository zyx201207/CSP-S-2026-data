# include <bits/stdc++.h>
# define int long long
using namespace std;

using ll = long long;

static const int N = 5e2 + 5, M = 5e5 + 5;
static const ll INF = 1e18 + 5;
vector <int> H[M];
vector <pair <int, int>> G[N]; 
ll c, n, m, d, q, g[M], dis[N][N], cnt[M], Gst[M][25];
bool vis[N];

priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater <pair <ll, int>>> pq;
inline void dijkstra (int st)
{
    while (!pq.empty ()) { pq.pop (); }
    pq.push ({0, st});
    while (!pq.empty ())
    {
        pair <ll, int> u = pq.top ();
        pq.pop ();
        if (vis[u.second])
        {
            continue ;
        }
        vis[u.second] = 1;
        for (pair <int, int> v : G[u.second])
        {
            if (dis[st][v.first] > dis[st][u.second] + v.second)
            {
                dis[st][v.first] = dis[st][u.second] + v.second;
                pq.push ({dis[st][v.first], v.first});
            }
        }
    }
}

signed main ()
{
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    ios :: sync_with_stdio (0);
    cin.tie (nullptr), cout.tie (nullptr);

    cin >> c >> n >> m >> d >> q;

    // cout << c << " " << n << " " << m << " " << d << " " << q << "\n";
    
    for (int i = 1; i <= m; i++)
    {
        cin >> g[i];
        // if (i % 100 == 1) cout << c << " " << n << " " << m << " " << d << " " << q << "\n";
    }

    // cout << c << " " << n << " " << m << " " << d << " " << q << "\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    } 

    for (ll i = 1, k, x, z; i <= n; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> x >> z;
            H[x].push_back (i);
            Gst[x][++ cnt[x]] = z;
        }
    }
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < H[i].size (); j++)
        {
            for (int k = 0; k < H[i].size (); k++)
            {
                if (H[i][j] == H[i][k]) { continue ; }
                dis[H[i][j]][H[i][k]] = min (dis[H[i][j]][H[i][k]], Gst[i][j + 1] + Gst[i][k + 1]);
            }
        }
    }

    // for (int k = 1; k <= n; k++)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         for (int j = 1; j <= n; j++)
    //         {
    //             dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
    //         }
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i != j) && (dis[i][j] != INF))
            {
                G[i].push_back ({j, dis[i][j]});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            vis[j] = 0;
        }
        dijkstra (i);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << dis[i][j] << " "; 
    //     }
    //     cout << "\n";
    // }
    
    ll ans = 0, ret = INF;
    for (int o = 1, x, y; o <= q; o++)
    {
        cin >> x >> y;
        ans = g[x] + g[y];
        // cout << x << " " << y << "\n";
        ret = INF;
        for (int i = 0; i < H[x].size (); i++)
        {
            for (int j = 0; j < H[y].size (); j++)
            {
                ret = min (ret, dis[H[x][i]][H[y][j]] + Gst[x][i + 1] + Gst[y][j + 1]);
            }
        }
        cout << (ans + ret) << "\n";
    }
    return 0;
}