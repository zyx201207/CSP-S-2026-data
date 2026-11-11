#include<bits/stdc++.h>
#define int long long
using namespace std;

int C, n, m, d, q, w[500005];
vector<pair<int, int>> l[505];
vector<pair<int, int>> s[500005];
struct Edge {
    bool isFixed;
    int u, v, t, dis;
    Edge() : 
        isFixed(false), t(-1), dis(LONG_LONG_MAX) 
    {}
}g[505][505];

struct Node {
    int cur, id;
    Node(int _cur, int _id) : cur(_cur), id(_id) {}
};
queue<Node> qq;
void dij(int x) {
    g[x][x].dis = 0;
    qq.emplace(Node(0, x));
    while(!qq.empty()) {
        Node now = qq.front(); qq.pop();
        if(g[x][now.id].isFixed) continue;
        g[x][now.id].isFixed = true;
        for(int i = 1; i <= n; i++) {
            if(g[now.id][i].t == -1) continue;
            if(g[x][i].dis > now.cur + g[now.id][i].t) {
                g[x][i].dis = now.cur + g[now.id][i].t;
                qq.emplace(g[x][i].dis, i);
            }
        }
    }
}

signed main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> C >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        int k, a, t; cin >> k;
        for(int j = 1; j <= k; j++) {
            cin >> a >> t;
            for(int p = 0; p < s[a].size(); p++) {
                if(g[s[a][p].first][i].t == -1) g[s[a][p].first][i].t = g[i][s[a][p].first].t = t + s[a][p].second;
                else g[s[a][p].first][i].t = g[i][s[a][p].first].t = min(g[s[a][p].first][i].t, t + s[a][p].second);
            }
            l[i].emplace_back(a, t);
            s[a].emplace_back(i, t);
        }
    }
    for(int i = 1; i <= n; i++) {
        dij(i);
    }
    for(int i = 1; i <= q; i++) {
        int x, y, flag1, flag2, ans = LONG_LONG_MAX;
        cin >> x >> y;
        for(int j = 0; j < s[x].size(); j++) {
            for(int k = 0; k < s[y].size(); k++) {
                if(ans > g[s[x][j].first][s[y][k].first].dis) {
                    ans = g[s[x][j].first][s[y][k].first].dis;
                    flag1 = s[x][j].second, flag2 = s[y][k].second;
                }
            }
        }
        ans += w[x] + w[y] + flag1 + flag2;
        cout << ans << '\n';
    }

    return 0;
}