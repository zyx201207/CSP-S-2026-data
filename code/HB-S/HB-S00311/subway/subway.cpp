#include <bits/stdc++.h>
#define ll long long
#define FILE(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;

const int N = 510, M = 500100;

int n, m, d, q;
ll W[M];
vector<pair<int, ll> > em[M]; // m's edge {subway, dis}
ll G[N][N], dis[N][N];

void floyd() {
    memset(dis, 63, sizeof dis);
    for(int i = 1; i <= n; i++) G[i][i] = 0;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = min(G[i][j], G[j][i]);
    for(int j = 1; j <= n; j++)
    for(int i = 1; i <= n; i++)
    for(int k = 1; k <= n; k++)
        dis[i][k] = min(dis[i][k], dis[i][j] + dis[j][k]);
}

int main() {
    FILE("subway");
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int cid; cin >> cid;
    cin >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> W[i];
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            int a, b; cin >> a >> b;
            em[a].push_back({i, b});
        }
    }
    memset(G, 63, sizeof G);
    for(int i = 1; i <= m; i++) {
        int tmp = em[i].size();
        for(int x = 0; x < tmp; x++) for(int y = x + 1; y < tmp; y++) {
            pair<int, ll> &X = em[i][x], &Y = em[i][y];
            G[X.first][Y.first] = min(G[X.first][Y.first], X.second + Y.second);
        }
    }
    floyd();
    while(q--) {
        int a, b; cin >> a >> b;
        ll res = 1e18;
        for(pair<int, ll> &x : em[a]) for(pair<int, ll> &y : em[b]) {
            res = min(res, dis[x.first][y.first] + x.second + y.second);
        }
        cout << res + W[a] + W[b] << '\n';
    }
    return 0;
}