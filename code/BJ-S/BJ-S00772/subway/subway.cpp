#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int MAXN = 2E5 + 50;
vector<pii> g[4 * MAXN];
//1biedian : zhantai
//2beidian : zhanting
//3beidian : chuzhankuo
//4beidian : bazhengtiaoxianluxiangxiangchenyigedian
int w[MAXN];
int t[550][MAXN];
int a[550][MAXN];
int k[1000];
int dist[4 * MAXN];
int st[4 * MAXN];
int c, n, m, d, q;
signed main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
        g[m + i].push_back({2 * m + i, w[i]});
        g[2 * m + i].push_back({m + i, w[i]});
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            g[m + a[i][j]].push_back({3 * m + i, t[i][j]});
            g[3 * m + i].push_back({m + a[i][j], t[i][j]});
        }
    }



    while (q--) {
        int s, ed;
        cin >> s >> ed;
        s = 2 * m + s;
        ed = 2 * m + ed;
        for (int i = 1; i <= 3 * m + n; i++) {
            dist[i] = 0x3f3f3f3f;
            st[i] = 0;
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        dist[s] = 0;
        q.push({s, dist[s]});
        while (!q.empty()) {
            auto id = q.top();
            q.pop();
            int u = id.first;
            if (st[u] == 1) continue;
            st[u] = 1;
            for (auto edge : g[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    //cout << v << ' ';
                    //cout << dist[v] << "   ";
                    q.push({v, dist[v]});
                }
            }
            //cout << endl;
        }
        cout << dist[ed] << '\n';
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


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
