

#include <iostream>
#include <vector>
#include <queue>

#define int long long

using namespace std;

const int MAXM = 5e5 + 9;
const int MAXN = 509;

int c, n, m, d, question;
int w[MAXM];

vector<pair<int, int>> zhanToXian[MAXM];

vector<pair<int, int>> G[MAXN];


struct Node {
    int u, dis;
};

bool operator > (Node one, Node two) {
    return one.dis > two.dis;
}

priority_queue<Node, vector<Node>, greater<Node> > q;

int dis[MAXN][MAXN];

void Dijkstra (int st) {
    for (int i = 1; i <= n; i++) dis[st][i] = 1e18;
    dis[st][st] = 0;

    Node solo;
    solo.u = st, solo.dis = 0;
    q.push(solo);
    while (!q.empty()) {
        solo = q.top(), q.pop();
        int u = solo.u;
        if (solo.dis != dis[st][u]) continue;

        for (pair<int, int> pr : G[u]) {
            int v = pr.first, w = pr.second;
            if (dis[st][v] > dis[st][u] + w) {
               dis[st][v] = dis[st][u] + w;

               Node cur;
               cur.u = v, cur.dis = dis[st][v];
               q.push(cur);
            }
        }
    }
}

signed main () {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> n >> m >> d >> question;
    for (int i = 1; i <= m; i++) cin >> w[i];

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int a, t;
            cin >> a >> t;
            zhanToXian[a].push_back({i, t});
        }
    }

    for (int i = 1; i <= m; i++) {
        for (pair<int, int> pr1 : zhanToXian[i]) {
            for (pair<int, int> pr2 : zhanToXian[i]) {
                int xian1 = pr1.first, dis1 = pr1.second;
                int xian2 = pr2.first, dis2 = pr2.second;
                if (xian1 != xian2) {
                    G[xian1].push_back({xian2, dis1 + dis2});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) Dijkstra(i);

    while (question--) {
        int x, y;
        cin >> x >> y;

        int ans = 1e18;
        for (pair<int, int> pr1 : zhanToXian[x]) {
            for (pair<int, int> pr2 : zhanToXian[y]) {
                int xian1 = pr1.first, dis1 = pr1.second;
                int xian2 = pr2.first, dis2 = pr2.second;
                ans = min(ans, dis1 + dis[xian1][xian2] + dis2);
            }
        }
        ans += w[x] + w[y];

        cout << ans << '\n';
    }

    return 0;
}
