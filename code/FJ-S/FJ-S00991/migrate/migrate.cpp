#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5, INF = LONG_LONG_MAX - 1;
ll c, t, n, d, x[N], dis[5005][5005], num[5005][5005];
struct node {
	int id, dis;
	bool operator < (const node x) const {dis > x.dis;};
};
vector<node> g[5005];
priority_queue<node> q;
void dijkstra(int s) {
	for(int i = 0; i <= n; i++) dis[s][i] = 1e18;
	dis[s][s] = 0;
	q.push({s, 0});
	while(!q.empty()) {
		int u = q.top().id;
		q.pop();
		for(auto v : g[u]) 
			if(dis[s][u] + v.dis < dis[s][v.id]) {
				dis[s][v.id] = dis[s][u] + v.dis;
				q.push({v.id, dis[s][v.id]});
			}
	}
}
void solve_1() { // subtask 1 ~ 6
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) 
			if(abs(x[i] - x[j]) <= d) {
				g[i].push_back({j, abs(x[i] - x[j])});
				g[j].push_back({i, abs(x[i] - x[j])});
			}
	for(int i = 1; i <= n; i++) dijkstra(i);
	for(int u = 1; u <= n; u++) {
		for(int v = 1; v <= n; v++) {
			
		}
	}
}


void solve_2() {
	int gongcha = x[2] - x[1];
	if(2 * gongcha > d) cout << 0;
	else cout << n - 2;
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		solve_2(); 
	}
} 
