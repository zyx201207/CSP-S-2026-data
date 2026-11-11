#include <bits/stdc++.h>
using namesapce std;
#define ll long long
const int N = 505;
ll c, n, m, d, q;
ll dis[N];
struct emm {
    int v, w;
};
void dijkstra(int s) {
    priority_queue<emm> q;
    q.push(s);
    memset(dis, -0x3f, sizeof dis);
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        for (auto e : g[u]) {
            int v = e.v, w = e.w;
            if (dis[u] >= dis[v] + w) {
                dis[u] = dis[v] + w;
                q.push({v, -dis[u]});
            }
        }
    }
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    while (t--) {
        cout << d << '\n';
    }
	return 0;
}
