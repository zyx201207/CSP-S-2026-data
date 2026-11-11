#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

const int N = 5e5 + 5;

bool MBE;

int n, m, d, q;
int w[N];
vector<int> a[505];
vector<int> t[505];

bool MED;

namespace SUB1 {

    int h[N], idx;
    struct Edge {
        int to, next, w;
    }edge[N << 1];
    int dis[3005][3005];
    int tot;
    bool vis[3005];

    inline void addedge(int x, int y, int w) {
        edge[++ idx] = {y, h[x], w};
        h[x] = idx;
    }

    inline void dij(int st) {
        for (int i = 1; i <= tot; ++ i) {
            vis[i] = 0;
            dis[st][i] = 1e17;
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dis[st][st] = 0;
        pq.push({0, st});
        while (pq.size()) {
            auto tp = pq.top();
            pq.pop();
            int x = tp.second;
            if (vis[x]) continue;
            vis[x] = 1;
            for (int i = h[x]; i; i = edge[i].next) {
                int to = edge[i].to, w = edge[i].w;
                if (dis[st][to] > dis[st][x] + w) {
                    dis[st][to] = dis[st][x] + w;
                    pq.push({dis[st][to], to});
                }
            }
        }
    }

    inline void Main() {
        cin >> n >> m >> d >> q;
        for (int i = 1; i <= m; ++ i) cin >> w[i];
        tot = m;
        for (int i = 1; i <= n; ++ i) {
            int k;
            cin >> k;
            int lst = -1;
            for (int j = 0, x, _t; j < k; ++ j) {
                cin >> x;
                a[i].push_back(++ tot);
                if (lst != -1) {
                    addedge(lst, tot, 0);
                    addedge(tot, lst, 0);
                }
                lst = tot;
                cin >> _t;
                t[i].push_back(_t);
                addedge(x, tot, _t);
                addedge(tot, x, _t);
            } 
        }
        for (int i = 1; i <= m; ++ i) dij(i);
        while (q --) {
            int x, y;
            cin >> x >> y;
            cout << dis[x][y] + w[x] + w[y] << "\n";
        }
    }
}

signed main() {
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
    // freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int c;
    cin >> c;
    if (c <= 11) SUB1 :: Main();


    // cerr << "Time: " << 1e3 * clock() / CLOCKS_PER_SEC << "ms\n";
    // cerr << "Memory: " << (&MED - &MBE) / 1024.0 / 1024.0 << "MB\n";
    return 0;
}