#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int c, n, m, d, q, x, y;
int w[N], a, t, k[505];
int head[N << 1], tot, dis[N << 1]; 
struct node {
    int nxt, to, val;
}e[N << 1];
void add(int x, int y, int z) {
    e[++tot] = {head[x], y, z};
    head[x] = tot;
}
struct edge {
    int pos, tar;
    bool operator < (const edge &x) const {
        return tar < x.tar;
    }
};
int dijkstra(int x, int y) {
    priority_queue<edge> q;
    memset(dis, 0x3f, sizeof dis);
    dis[x] = 0;
    q.push({x, 0});
    while(!q.empty()) {
        edge t = q.top(); q.pop();
        int u = t.pos;
        for(int i = head[u]; ~i; i = e[i].nxt) {
        	int v = e[i].to;
            if(dis[v] > dis[u] + e[i].val) {
                dis[v] = dis[u] + e[i].val;
                q.push({v, dis[v]});
            }
		}
    }
    return dis[y];
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    memset(head, -1, sizeof head);
    tot = -1;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++) {
            cin >> a >> t;
            add(i + m, a, t), add(a, i + m, t);
        }
    }
    while(q--) {
        cin >> x >> y;
        cout << dijkstra(x, y) + w[x] + w[y] << endl;
    }
	return 0;
}