#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

int c, t, n, k;
vector<int> E[500010];
vector<int> S;
unordered_map<int, int> vis;
int cnt;
void check(int s, int fa) {
	bool flag = true;
	for(int v : E[s]) {
		if(vis[v] == 2 || vis[v] == 0 || v == fa) continue;
		check(v, s);
		vis[v] = 2;
		flag = false;
	}
	if(flag && fa != 0) cnt++;
}
int res = LLONG_MAX;
int ans = 0;
vector<int> dist;
void getans() {
	ans = 0;
	for(int i = 1; i <= n; i++) {
		dist = vector<int>(n + 1, LLONG_MAX);
		queue<int> q;
		q.push(i);
		dist[i] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(int v : E[u]) {
				if(dist[v] > dist[u] + 1) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		int mn = LLONG_MAX;
		for(int j = 0; j < S.size(); j++) mn = min(mn, dist[S[j]]);
//		cout << mn << "\n";
//		if(i == 5) cout << dist[4] << "\n";
		ans = max(ans, mn);
	}
}
void dfs1(int K, int j, int sum) {
	if(sum == k) {
		vis.clear();
		for(int i = 0; i < sum; i++) vis[S[i]] = 1;
		for(int i = 0; i < sum; i++) {
			if(vis[S[i]] == 2) continue;
			vis[S[i]] = 2;
			check(S[i], 0);
		}
		if(cnt == K) {
//			if(S[0] == 2 && S[1] == 7 && S[2] == 9) cout << "A\n";
			getans(), res = min(ans, res);
//			cout << "B\n";
		}

		return ;
	}
	for(int i = j; i <= n; i++) {
		if(k - sum + 1 > n - j) break;
		S.push_back(i);
		dfs1(K, i + 1, sum + 1);
		S.pop_back();
	}
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= 500009; i++) E[i] = vector<int>();
		for(int i = 1; i <= n; i++) {
			int x, y; cin >> x >> y;
			E[x].push_back(y);
			E[y].push_back(x); 
		}
		
		for(int K = 1; K <= 2; K++) {
			dfs1(K, 1, 0);
		}
		cout << res << "\n";
	}
	
	return 0;
} 


