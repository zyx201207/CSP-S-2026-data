#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
using LL = long long;

constexpr int MAX_N = 505, MAX_M = 5e5+5;
constexpr LL INFTY = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    int to = 0;
    LL dis = 0;

    Edge(int to, LL dis):
        to(to), dis(dis) {}

    friend bool operator < (const Edge &u, const Edge &v) {
        return u.dis > v.dis;
    }
};

int c, n, m, d, q;
LL dist[MAX_N][MAX_N], w[MAX_M];
vector<pair<int, LL>> stat[MAX_M];

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i ++) {
        cin >> w[i];
    }
    memset(dist, 0x3f, sizeof(dist));
    for(int i = 1; i <= n; i ++) dist[i][i] = 0;
    for(int i = 1; i <= n; i ++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j ++) {
            int now;
            LL v;
            cin >> now >> v;
            for(auto o : stat[now]) {
                dist[i][o.first] = dist[o.first][i] = min(dist[i][o.first], v + o.second);
            }
            stat[now].emplace_back(make_pair(i, v));
        }
    }
    for(int k = 1; k <= n; k ++) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q --) {
        int x, y;
        cin >> x >> y;
        LL ans = INFTY;
        for(auto i : stat[x]) {
            for(auto j : stat[y]) {
                ans = min(ans, i.second + j.second + dist[i.first][j.first]);
            }
        }
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}
