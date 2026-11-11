#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int MAX = 5e5 + 10;
int c, n, m, d, q;
int w[MAX], dis[MAX];
vector<pii> g[MAX];
void Dijkstra(int s){
	memset(dis, 0x3f, sizeof dis);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({s, 0});
	dis[s] = w[s];
	while (!pq.empty()){
		auto p = pq.top();
		pq.pop();
		int u = p.first, w = p.second;
		for (auto vv : g[u]){
			int v = vv.first, v_w = vv.second;
			if (dis[v] > dis[u] + w + v_w){
				dis[v] = dis[u] + w + v_w;
				pq.push({v, dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		int s;
		cin >> s;
		for (int j = 1, wz, zx; j <= s; j++){
			cin >> wz >> zx;
			g[i].push_back({wz, zx});
			g[wz].push_back({i, zx});
		}
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		Dijkstra(x);
		cout << dis[y] + w[y] << '\n';
	}
	return 0;
}
