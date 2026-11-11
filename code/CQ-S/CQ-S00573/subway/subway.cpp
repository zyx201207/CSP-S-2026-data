#include <bits/stdc++.h>
#define all(x) x.begin (), x.end ()
#define x first
#define y second
using namespace std;
using ll = long long;
using db = double;
const ll INF = ll (1e18) + 7;

template <typename T>
inline void cmax (T &a, const T &b) {if (a < b) a = b;}
template <typename T>
inline void cmin (T &a, const T &b) {if (a > b) a = b;}

void init () {

}

void solve () {
    int n, m, d, q; cin >> n >> m >> d >> q;
    vector <ll> a (m + 1, 0ll);
    for (int i = 1; i <= m; i++) cin >> a[i];

    vector <vector <pair <int, ll>>> e (m + 1, vector <pair <int, ll>> ());
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        while (k--) {
            int v; ll w; cin >> v >> w;
            e[v].emplace_back (i, w);
        }
    }

    vector <vector <ll>> dis (n + 1, vector <ll> (n + 1, INF));
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++) for (int j = 0; j < e[i].size (); j++) for (int k = j + 1; k < e[i].size (); k++) {
        int v = e[i][j].x, u = e[i][k].x;
        ll w = e[i][j].y + e[i][k].y;
        cmin (dis[v][u], w);
        cmin (dis[u][v], w);
    }

    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        cmin (dis[i][j], dis[i][k] + dis[k][j]);
    
    while (q--) {
        int v, u; cin >> v >> u;
        ll ans = INF;
        for (auto x : e[v]) for (auto y : e[u])
            cmin (ans, dis[x.x][y.x] + x.y + y.y + a[v] + a[u]);
        cout << ans << '\n';
    }
}

int main () {
#ifndef ONLINE_JUDGE
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
#endif
    ios :: sync_with_stdio (0);
    cin.tie (0), cout.tie (0);

    init ();

    int t = 1, c;
    cin >> c;
    // cin >> t;
    while (t--) solve ();

    return 0;
}