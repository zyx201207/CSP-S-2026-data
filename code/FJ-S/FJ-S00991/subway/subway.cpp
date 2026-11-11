#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 5;
ll c, n, m, d, qq, a, t, cnt, sum, w[100005], k[100005], dis[N][N], dis2[100005];
struct node {
	ll id, dis;
	bool operator < (const node x) const {return dis < x.dis;};
}; 
priority_queue<node> q;
vector<node> g[N], g2[100005];
void dijkstra(int s) {
	for(int i = 0; i <= cnt; i++) dis[s][i] = 1e18;
	dis[s][s] = 0;
	q.push({s, 0});
	while(!q.empty()) {
		ll u = q.top().id;
		q.pop();
		for(auto v : g[u]) 
			if(dis[s][u] + v.dis < dis[s][v.id]) {
				dis[s][v.id] = dis[s][u] + v.dis;
				q.push({v.id, dis[s][v.id]});
			}
	}
}
void dijkstra2(int s) {
	for(int i = 0; i <= cnt; i++) dis2[i] = 1e18;
	dis2[s] = 0;
	q.push({s, 0});
	while(!q.empty()) {
		ll u = q.top().id;
		q.pop();
		for(auto v : g2[u]) 
			if(dis2[u] + v.dis < dis2[v.id]) {
				dis2[v.id] = dis2[u] + v.dis;
				q.push({v.id, dis2[v.id]});
			}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> qq;
	cnt = m;
	for(int i = 1; i <= m; i++) cin >> w[i];
	if(c <= 11) {
		for(int i = 1; i <= n; i++) {
			cin >> k[i];
			int last = 0;
			for(int j = 1; j <= k[i]; j++) {
				cin >> a >> t;
				cnt++;
				g[a].push_back({cnt, t});//cout << a << ' ' << cnt << ' ' << t << endl;
				g[cnt].push_back({a, t});//cout << cnt << ' ' << a << ' ' << t << endl;
				if(last) {
					g[last].push_back({cnt, 0});//?
					g[cnt].push_back({last, 0});
					//cout << last << ' ' << cnt << " 0" << endl;
				}
				last = cnt; 
			}
		}
		for(int i = 1; i <= cnt; i++) dijkstra(i);
		//for(int i = 1; i <= cnt; i++) {
		//	for(int j = 1; j <= cnt; j++) cout << dis[i][j] << ' ';
		//	cout << endl;
		//}
		ll xx, yy;
		while(qq--) {
			cin >> xx >> yy;
			cout << dis[xx][yy] + w[xx] + w[yy] << '\n';
		}
	} else {
		for(int i = 1; i <= n; i++) {
			cin >> k[i];
			int last = 0;
			for(int j = 1; j <= k[i]; j++) {
				cin >> a >> t;
				cnt++;
				g2[a].push_back({cnt, t});//cout << a << ' ' << cnt << ' ' << t << endl;
				g2[cnt].push_back({a, t});//cout << cnt << ' ' << a << ' ' << t << endl;
				if(last) {
					g2[last].push_back({cnt, 0});//?
					g2[cnt].push_back({last, 0});
					//cout << last << ' ' << cnt << " 0" << endl;
				}
				last = cnt; 
			}
		}
		ll xx, yy;
		while(qq--) {
			cin >> xx >> yy;
			dijkstra2(yy);
			cout << dis2[xx] + w[xx] + w[yy] << '\n';
		}
	}
	return 0;
} 
