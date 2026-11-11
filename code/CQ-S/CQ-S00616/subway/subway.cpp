#include<bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
typedef long long ll;
int c, n, m, d, q;
ll w[N];
int k[N];
typedef pair<ll, int> pii;
vector<pair<int, ll> > e[N];
ll ans[2005][2004];
bool vis[30005];
ll dis[30004];
void bfs(int s) {
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push({0, s});
	for (int i = 1; i <= n + m; i++) vis[i] = 0, dis[i] = 0x3f;
	dis[s] = 0;
	while(!q.empty()) {
		int now = q.top().second;
		q.pop();
		vis[now] = 1;
		for (auto [x, y] : e[now]) {
			if(vis[x]) {
				continue;
			}
			if(dis[x] > dis[now] + y) {
				dis[x] = dis[now] + y;
				q.push({dis[x], x});
			}
		}
	}
}
void solve1() {
	for (int i = 1; i <= m; i++) {
		bfs(i);
		for (int j = 1; j <= m; j++) {
			ans[i][j] = dis[j] + w[i] + w[j];
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		cout << ans[x][y] << '\n';
	}
}
void solve2() {
	while(q--) {
		int x, y;
		cin >> x >> y;
		bfs(x);
		cout << w[x] + w[y] + dis[y] << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("subway5.in", "r", stdin);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			ll t, x;
			cin >> x >> t;
			e[m + i].push_back({x, t});
			e[x].push_back({m + i, t});
		}
	}
	if(m <= 1000) {
		solve1();
		return 0;
	}
	solve2();
	
}
/*
建图？ 
欧克
刚想到n^3的做法一看数据范围 
哇塞~~~~~
直接真爱降临了
去去去，撤回我刚刚说的话
这里的n好像不是我想的那个
ku...
qaq
算了
先总结一下
已知我的建图方法
一个地铁站的连边不超过20
路线数不超过500
（记得开long long)
总点数会达到5e5多一点
总边数会达到1e7
布什戈门，这咋做
let me think think
好像可以用LCA，来求两点之间的最短路径 
这不是一棵树 
*/
