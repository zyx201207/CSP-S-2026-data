#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
const ll N = 500;
const ll M = 5e5;
const ll INF = 1e18;

ll w[M + 5];
ll dist[N + 5][N + 5];

struct Line
{
    ll id;
    ll t;
};

vector<Line> lines[M + 5];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;

    for (ll i = 1; i <= m; ++i) cin >> w[i];

    for (ll i = 1; i <= n; ++i)
    {
        ll k;
        cin >> k;
        while (k--)
        {
            ll u, t;
            cin >> u >> t;
            lines[u].push_back({i, t});
        }
    }

    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= n; ++j)
            if (i != j)
                dist[i][j] = INF;

    for (ll j = 1; j <= m; ++j)
    {
        for (Line e1 : lines[j])
        {
            ll u1 = e1.id;
            ll w1 = e1.t;
            for (Line e2 : lines[j])
            {
                ll u2 = e2.id;
                ll w2 = e2.t;
                dist[u1][u2] = min(dist[u1][u2], w1 + w2);
                dist[u2][u1] = min(dist[u2][u1], w1 + w2);
            }
        }
    }

    for (ll k = 1; k <= n; ++k)
        for (ll i = 1; i <= n; ++i)
            for (ll j = 1; j <= n; ++j)
                if (i != j && i != k && j != k)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    while (q--)
    {
        ll x, y;
        cin >> x >> y;

        ll res = INF;
        for (Line e1 : lines[x])
        {
            ll u1 = e1.id;
            ll w1 = e1.t;
            for (Line e2 : lines[y])
            {
                ll u2 = e2.id;
                ll w2 = e2.t;
                res = min(res, w1 + w2 + dist[u1][u2]);
            }
        }

        cout << w[x] + w[y] + res << endl;
    }

    return 0;
}