#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
struct node{
    int to, val, line;
};
priority_queue<node , vector<node>, greater<int> > pq;
vector<pair<int, int> > G[500005];
bool vis[500005], vis1[505][500005];
int main(){
    cin >> c >> n >> m >> d >> q;
    if (c >= 7&&c <= 11) {
        int w[80005], a[505][500005], t[205][80005], k[505];
        for (int i = 1;i <= m;++ i) cin >> w[i];
        for (int i = 1;i <= n;++ i) {
            cin >> k[i];
            for (int j = 1;j <= k[i];++ j){
                cin >> a[i][j] >> t[i][j];
                if (j == 1) continue ;
                G[a[i][j - 1]].push_back({a[i][j], t[i][j]});
                G[a[i][j]].push_back({a[i][j - 1], t[i][j - 1]});
                vis1[i][a[i][j]] = 1;
            }
        }
        long long ans = 0, dis[500005];
        while (q --){
            int x, y;
            cin >> x >> y;
            pq.push({x, w[x]});
            dis[x] = 0;
            while (!pq.empty()){
                node now = pq.top();
                pq.pop();
                int u = now.to;
                int l = now.line;
                if (vis[u]) continue ;
                vis[u] = 1;
                for (auto y : G[u]){
                    int v = y.first, d;
                    if (vis1[l][v]) d = 0;
                    else
                        d = now.second + y.second;
                    if (dis[u] + d < dis[v])
                        dis[v] = dis[u] + d;
                }
            }
        }
        cout << dis[y] << endl;
    }
    return 0;
}
