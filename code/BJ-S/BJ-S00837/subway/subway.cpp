#include <bits/stdc++.h>
#define pii pair<int, int>
#define mkp(a, b) make_pair(a, b)
using namespace std;
const int M = 5e5 + 1005;
const int N = 505 + 5;
struct Edge {
    int u, v;
    long long w;
    int next;
} e[M * 2];
int head[N], ohead[N], cur = 0;
void add(int u, int v, int w) {
    // cout << "Edge add " << u << " " << v << " " << w << " " << head[u] << endl;
    e[++cur] = Edge{u, v, w, head[u]};
    head[u] = cur;
}
int c, n, m, d, q;
vector<pii> G[M];
long long dist[N];
bool vis[N];
void Dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[s] = 0;
    priority_queue<pii> q;
    q.push(mkp(0, s));
    while(!q.empty()) {
        pii tmp = q.top();
        // cout << tmp.first << " " << tmp.second << endl;
        q.pop();
        int u = tmp.second;
        vis[u] = 0;
        for(int i = head[u]; i; i = e[i].next) {
            // cout << i << endl;
            if(dist[u] + e[i].w < dist[e[i].v]) {
                dist[e[i].v] = dist[u] + e[i].w;
                if(!vis[e[i].v]) {
                    q.push(mkp(dist[e[i].v], e[i].v));
                    vis[e[i].v] = 1;
                }
            }
        }
    }
}
int trans[M];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> trans[i];
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(mkp(i, y));
        }
    }
    for(int i = 1; i <= m; i++) {
        int siz = G[i].size();
        for(int j = 0; j < siz; j++) {
            for(int k = j + 1; k < siz; k++) {
                add(G[i][j].first, G[i][k].first, G[i][j].second + G[i][k].second);
                add(G[i][k].first, G[i][j].first, G[i][j].second + G[i][k].second);
            }
        }
    }
    int CUR = cur;
    for(int i = 1; i <= n; i++) ohead[i] = head[i];
    while(q--) {
        head[n + 1] = head[n + 2] = 0;
        for(int i = 1; i <= n; i++) head[i] = ohead[i];
        cur = CUR;
        int S, T;
        cin >> S >> T;
        int sizS = G[S].size();
        int sizT = G[T].size();
        for(int i = 0; i < sizS; i++) {
            add(n + 1, G[S][i].first, G[S][i].second);
            add(G[S][i].first, n + 1, G[S][i].second);
        }
        for(int i = 0; i < sizT; i++) {
            add(n + 2, G[T][i].first, G[T][i].second);
            add(G[T][i].first, n + 2, G[T][i].second);
        }
        Dijkstra(n + 1);
        // cout << "Dij out" << endl;
        cout << dist[n + 2] + trans[S] + trans[T] << endl;
    }
    return 0;
}
// 15:08 出思路，难道这把王朝了？
// 15:21 微调了一下思路，感觉时间比较吃紧啊。
// 15:58 完成。