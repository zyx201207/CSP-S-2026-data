#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 5;
int n, k, dis[N], ans;
bool chose[N];

vector<int> v[N];

inline void init() {
	ans = 1e18;
	for(int i = 1; i <= n; ++i) {
		v[i].clear();
		chose[i] = false;
	}
		
}

inline bool check(vector<int> arr) {
	int cnt = 0;
	bitset<N> vis;
	for(int i : arr) {
		if(vis[i]) continue;
		++ cnt;
		if(cnt > 2) return false;
		queue<int> q;
		vis[i] = true;
		q.push(i);
		while(q.size()) {
			int x = q.front(); q.pop();
			for(int p : v[x]) {
				if(vis[p] || !chose[p]) continue;
				vis[p] = true;
				q.push(p);
			}
		}
	}
	return true;
}

void dfs(int x, vector<int> use) {
	if(n - x + 1 + (int)use.size() < k || (int)use.size() > k) return ;
	if(x == n + 1) {
		if(!check(use)) return ;
		int r = 0;
		for(int mi, i = 1; i <= n; ++i) {
			if(chose[i]) continue;
			queue<int> q;
			q.push(i);
			bitset<N> vis;
			vis[i] = true;
			for(int j = 1; j <= n; ++j)
				dis[j] = 1e18;
			dis[i] = 0;
			while(q.size()) {
				int u = q.front(); q.pop();
				for(int p : v[u]) {
					if(vis[p]) continue;
					q.push(p);
					vis[p] = true;
					dis[p] = dis[u] + 1;
				}
			}
			mi = 1e18;
			for(int j : use)
			if(chose[j]) mi = min(mi, dis[j]);
			r = max(r, mi);
		}
		ans = min(ans, r);
		return ;
	}
	vector<int> old = use;
	use.push_back(x);
	chose[x] = true;
	dfs(x + 1, use);
	chose[x] = false;
	dfs(x + 1, old);
}

void solve() {
	cin >> n >> k;
	init();
	for(int x, y, i = 1; i < n; ++i) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<int> no;
	dfs(1, no);
	cout << ans << endl;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(0); cin.tie(0);

	int _, T; cin >> _ >> T;
	while(T --) solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

15 pts
*/
