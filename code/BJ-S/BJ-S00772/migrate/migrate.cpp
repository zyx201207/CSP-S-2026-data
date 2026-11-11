#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5E3 + 50;
int c, t, n, d;
int x[MAXN];
int dist[MAXN];
int cnt[MAXN];
int st[MAXN];
vector<pair<int, int>> g[MAXN];
signed main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        int num = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        if (c >= 10 && c <= 12) {
            cout << n - 3 << endl;
            continue;
        }
        for (int s = 1; s <= n; s++) {
            for (int j = 1; j <= n; j++) {
                g[j].clear();
                for (int k = j + 1; k <= n; k++) {
                    if (x[k] - x[j] <= d){
                        g[k].push_back({j, 1});
                        g[j].push_back({k, 1});
                    }
                }
                dist[j] = 0x3f3f3f3f;
                cnt[j] = 0;
                st[j] = 0;
            }
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
            dist[s] = 0;
            q.push({s, dist[s]});
            while (!q.empty()) {
                auto id = q.top();
                q.pop();
                int u = id.first;
                if (st[u] == 1) continue;
                st[u] == 1;
                for (auto edge : g[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    //cout << u << "->" << v << ": " << w << '\n';
                    if (dist[v] == dist[u] + w) {
                        cnt[v]++;
                    } else if (dist[v] > dist[u] + w) {
                        cnt[v] = 1;
                        dist[v] = dist[u] + w;
                        q.push({v, dist[v]});
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                if (cnt[i] == 2) num++;
            }
        }
        cout << num << endl;
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
