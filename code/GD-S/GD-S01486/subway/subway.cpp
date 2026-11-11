#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005];
vector<int> a;
vector<int> t;
struct edge{
	int v, w;
};
vector<vector<edge>> g;
struct way{
	int time, now;
	bool operator>(const way b) const{
		return time > b.time;
	}
};
bool vis[500005];
int aaa(int st, int ed){
	memset(vis, 0, sizeof(vis));
	priority_queue<way, vector<way>, greater<way>> q;
	q.push({w[st], st});
	vis[st] = 1;
	while(!q.empty()){
		way u = q.top();
//		cout << u.time << " " << u.now << endl;
		q.pop();
		if (u.now == ed){
			return u.time + w[u.now];
		}
		for (int i = 0; i < g[u.now].size(); i++){
			int v = g[u.now][i].v;
			if (!vis[v]){
				q.push({u.time + g[u.now][i].w, v});
				vis[v] = 1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	g.resize(m + 1);
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		a.resize(k + 1);
		t.resize(k + 1);
		for (int j = 1; j <= k; j++){
			cin >> a[j] >>  t[j];
		}
		for (int j1 = 1; j1 <= k; j1++){
			for (int j2 = j1 + 1; j2 <= k; j2++){
				g[a[j1]].push_back({a[j2], t[j1] + t[j2]});
				g[a[j2]].push_back({a[j1], t[j1] + t[j2]});
			}
		}
	}
	for (int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		cout << aaa(x, y) << endl;
	}
	return 0;
}
