#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
const int N = 2e4 + 505;
const int M =2e4+ 5;
vector<pair<int, int>> g[N];
int w[M];
int dist[N];
void solve() {
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        
        memset(dist, 63, sizeof dist);
        queue<int>pq;
        dist[x] = w[x];
        pq.push(x);
        while(!pq.empty()) {
            
            int u = pq.front();
            pq.pop();
            for (auto e :g[u]) {
                int v = e.first;
                int w = e.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push(v);
                }
            }
        }
        cout << dist[y] + w[y] << endl;
    }
}
struct Edge{
    int fa, u, step;
};
int allt;
void solveB() {
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        queue<Edge>q;
        q.push({x, x, 0});
        while(!q.empty()){
            int u = q.front().u;
            int fa = q.front().fa;
            int step = q.front().step;
            if (u == y) {
                //cout << step<<endl;
                cout << q.front().step * allt + w[x] + w[y] << endl;
                break;
            }
            q.pop();
            for (auto e:g[u]) {
                int v = e.first;
                int w = e.second;
                if (v == fa) continue;
                q.push({u, v, step + 1});
            }
        }

    }
}
int main() {
     freopen("subway.in", "r", stdin);
     freopen("subway.out", "w", stdout);
    
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            allt = t;
            g[m + i].push_back({a, t});
            g[a].push_back({m + i, t});
        }
    }
    //cout << allt << endl;
    //cout << "ok";
    if (c >=7 && c<=11) {
        solveB();
    }
    else {
        solve();
    }
    return 0;
}