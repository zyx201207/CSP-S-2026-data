#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int N = 5e5 + 10;
int c, n, m, d, q;
int w[N], dis[N], t[N], v[N];
bool vis[N];
vector<vector<P> > g;

void qwq(int bg) {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[bg] = 0;
    for (int i = 1; i <= m; i++) {
        int t = -1;
        for (int j = 1; j <= m; j++) {
            if (!vis[j] && (t == -1 || dis[t] > dis[j])) t = j;
        }
        vis[t] = 1;
        for (auto [v, w] : g[t]) if (!vis[v]) dis[v] = min(dis[v], dis[t] + w);
    }
    return ;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> n >> m >> d >> q;
    g.resize(m + 5);
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> v[j] >> t[j];
            for (int l = 1; l < j; l++) {
                g[v[l]].push_back({v[j], t[j] + t[l]});
                g[v[j]].push_back({v[l], t[j] + t[l]});
            }
        }
    }
    /*
    for (int u = 1; u <= m; u++) {
        for (auto [to, w] : g[u]) cout << u << " -> " << to << ' ' << w << '\n';
    }*/
    for (int x, y; q--; ) {
        cin >> x >> y;
        qwq(x);
        cout << w[x] + w[y] + dis[y] << '\n';
    }
    return 0;
}
