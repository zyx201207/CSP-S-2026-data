#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

ll c, m, n, d, q;
vector<ll> w;
vector<vector<ll>> mindis;
vector<vector<pii>> g; // 1 ~ m: halls | m + 1 ~ m + n: subway lines

void dj(ll s) {
    bool vis[m + n + 1];
    vector<ll> dis;
    dis.resize(m + n + 1);
    vis[s] = 1;
    for (ll i = 1 ; i <= m + n; i++) {
        if (i == s) {
            dis[i] = 0;
        } else {
            dis[i] = -1;
        }
    }
    for (ll i = 2 ; i <= m + n ; i++) {
        ll to = 0; pii edge = {0, -1};
        for (ll j = 1 ; j <= m + n ; j++) {
            if (vis[j]) {
                for (pii tmp : g[j]) {
                    if (edge.second == -1 || tmp.second < edge.second) {
                        to = j; edge = tmp;
                    }
                }
            }
        }
        dis[edge.first] = dis[to] + edge.second;
    }
    mindis[s] = dis;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> c >> m >> n >> d >> q;
    w.resize(m + 1);
    for (ll i = 1 ; i <= m ; i++) cin >> w[i];
    g.resize(m + n + 1);
    for (ll i = 1 ; i <= n ; i++) {
        ll k; cin >> k;
        while (k--) {
            ll a, t; cin >> a >> t;
            g[a].push_back({m + i, t});
            g[m + i].push_back({a, t});
        }
    }
    for (ll i = 1 ; i <= m + n ; i++) dj(i);
    while (q--) {
        ll x, y; cin >> x >> y;
        cout << mindis[x][y] + w[x] + w[y] << endl;
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