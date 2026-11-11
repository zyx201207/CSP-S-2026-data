#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
const int M = 5e5 + 10, N = 510;
struct re {
	int to, w;
};
vector<re> G[M];
int n, m, c, d, q, dis[N], a[N], in[N], e[N];
bool vis[N];
void fun(int x) {
	for (int i = 0; i <= m; i ++) dis[i] = 1e18, in[i] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({0, x}); dis[x] = 0; vis[x] = 1;
	while (!q.empty()) {
		int x = q.top().second; q.pop();
		vis[x] = 0;
		for (auto i : G[x]) {
			if (dis[i.to] > dis[x] + i.w) {
				dis[i.to] = dis[x] + i.w + e[x];
				in[i.to] = in[x] + 1;
				if (in[i.to] < m) q.push({dis[i.to], i.to});
			}
		}
	}
	return;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		int k, b, t; cin >> k;
		for (int j = 1; j <= k; j ++) {
			cin >> b >> t;
			if (b == i) e[i] = t;
			else {
				G[i].push_back({b, t});
				G[b].push_back({i, t});
			}
		}
	}
	while (q --) {
		int x, y; cin >> x >> y;
		fun(x); 
		cout << dis[y] + a[x] + a[y]<< '\n';
	}
	return 0;
}
