#include <bits/stdc++.h>
#define pi pair<int, int>
#define mp make_pair
using namespace std;
const int N = 505;
const int M = 2e6 + 5;
int c, n, m, d, q;
int k, tot;
int w[N], a[N], t[N];
int dis[N][N];
int ver[M], head[M], edge[M], Next[M];
bool vis[M];
priority_queue < pi, vector<pi>, greater<pi> > qq;

void add(int x, int y, int z) {
    ver[++tot] = y;
    Next[tot] = head[x];
    edge[tot] = z;
    head[x] = tot;
}

void dij(int s) {
    dis[s][s] = 0;
    qq.push(mp(0, s));
    while(qq.size()) {
        int u = qq.top().first;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i; i = Next[i]) {
            int v = ver[i];
            int w = edge[i];
            if(dis[s][v] > dis[s][u] + w) {
                dis[s][v] = dis[s][u] + w;
                qq.push(mp(dis[s][v], v));
            }
        }
    }

}

int main() {


    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        memset(a, 0, sizeof(a));
        memset(t, 0, sizeof(t));
        cin >> k;
        for(int j = 1; j <= k; j++) {
            cin >> a[j] >> t[j];
        }
        if(k == 2) {
            add(a[1], a[2], t[1] + t[2]);
            add(a[2], a[1], t[1] + t[2]);
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            dis[i][j] = INT_MAX;
        }
    }
    for(int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        if(dis[x][y] != INT_MAX && dis[x][y] > 0) {
            cout << dis[x][y] << endl;
            continue;
        }
        if(dis[x][y] != INT_MAX && dis[x][y] > 0) {
            cout << dis[y][x] << endl;
            continue;
        }
        dij(x);
        cout << w[x] + w[y] + dis[x][y] << endl;
    }

    return 0;
}
