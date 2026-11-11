#include <iostream>
#include <algorithm>
#include <utility>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 500, MAXM = 5e5, MAXD = 20, MAXQ = 1e5;
int c, n, m, d, qs, now = 2 * m + 1;
int dis[2000][2000];
vector<vector<pair<int, int> > > g;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
void dijkstra(int x) {
    fill(dis[x], dis[x] + 1900, 0xffffff);
    q.push(make_pair(0, x));
    dis[x][x] = 0;
    while (!q.empty()) {
        int d = q.top().first, k = q.top().second;
        //cout << d << " " << k << "\n";
        q.pop();
        if (d > dis[x][k]) continue;
        for (auto r : g[k]) {
            if (d + r.first < dis[x][r.second]) {
                dis[x][r.second] = d + r.first;
                q.push(make_pair(dis[x][r.second], r.second));
            }
        }
    }
    //cout << "end\n";
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> qs;
    g.resize(2 * m + 1);
    for (int i = 1; i <= m; i++) {
        int w;
        cin >> w;
        g[m + i].push_back(make_pair(w, i));//m+i:d
        g[i].push_back(make_pair(w, m + i));//i:t
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int prev = now++;
        for (int j = 1; j <= k; j++) {
            int aa, tt;
            cin >> aa >> tt;
            g.push_back({});
            g[aa].push_back(make_pair(tt, prev));
            g[prev].emplace_back(make_pair(tt, aa));
        }
    }
    now--;
    for (int i = 1; i <= m; i++) {
        dijkstra(i + m);
        for (int j = 1; j <= m; j++) {
            //cout << dis[i][j] << " ";
        }
        //cout << "\n";
    }
    for (int i = 1; i <= qs; i++) {
        int x, y;
        cin >> x >> y;
        cout << dis[m + x][m + y] << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

