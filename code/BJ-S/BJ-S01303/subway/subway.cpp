

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;


struct node{
    int v, w;
};
vector<node> g[500009];
int w[500009], k[500009], a[509][500009], t[509][500009], d[500009];
int n, m, f, p, c;
bool vis[5000009];
priority_queue<pair<int, int> > q;
void dijkstra (int s) {
    d[s] = 0;
    q.push(make_pair(0, s));
    //cout << d[s] << endl;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u] == true) {
            continue;
        }
        vis[u] = 1;
        //cout << g[u].size() << endl;
        for (int i = 0; i < g[u].size(); i++) {

            int v = g[u][i].v, w = g[u][i].w;
            if (vis[v] == 1) continue; 
           // cout << u << " " << v << " " << w << endl;
            if ((long long)d[u] + (long long)w < (long long)d[v]) {
                d[v] = (long long)d[u] + (long long)w;
                q.push(make_pair(-d[v], v));
            }
        }
    }
}

int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(d, 0x3F, sizeof(d));
    cin >> c >> n >> m >> f >> p;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            //cout << a[i][j] << " " << t[i][j] << endl;
        }
        //cout << endl;
        for (int j = 1; j <= k[i]; j++) {
            for (int x = j + 1; x <= k[i]; x++) {
                int u = a[i][j], v = a[i][x];
                cout << u << " " << v << endl;
                g[u].push_back({v, t[i][j] + t[i][x]});
                
                g[v].push_back({u, t[i][j] + t[i][x]});
                // if (u == 212) {
                //     cout << 1;
                // }
            }
            //cout <<1 << endl;
            //int u = a[i][j], v = a[i][j + 1];
            //cout << u << " " << v << endl;
            
        }
       
    }
    //cout << g[1][0].v << endl;
    while (p--) {
        memset(d, 0x3F, sizeof(d));
        memset(vis, 0, sizeof(vis));
        int x, y;
        cin >> x >> y;
        //cout << 1;
        dijkstra(x);
        cout << (long long) d[y] + (long long)w[x] + (long long)w[y] << endl;
    }
    //test
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 0; j < g[i].size(); j++) {
    //         cout << i << " " << g[i][j].v << " " << g[i][j].w << endl;
    //     }
    //     cout << endl;
    // }
    //testover
    return 0;
}