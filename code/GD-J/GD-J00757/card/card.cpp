#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int, int> pi; 
const int N = 5e5 + 114 + 514, M = 3e5 + 114 + 514;
vector<int> son[N];
int a[N], cnt[M], lstp[N], lst[M];
int n, m;
int dfs(int u, int fa) {
	int siz = 1;
	for(auto v : son[u]) {
		if(v == fa) continue;
		siz += dfs(v, u);
	}
	cnt[a[u]] = max(cnt[a[u]], siz);
	return siz;
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		lstp[i] = lst[a[i]];
		lst[a[i]] = i; 
	}
	queue<pi> q;
	q.push({n, 0});
	while(!q.empty()) {
		int u = q.front().first;
		int frm = q.front().second;
		q.pop();
		if(frm != 0) {
			son[frm].push_back(u);
			son[u].push_back(frm);
		}
		if(u != 1 && lst[a[u - 1]] == u - 1) {
			q.push({u - 1, u});
		}
		if(lstp[u] != 0) {
			q.push({lstp[u], u});
		}
	}
	dfs(n, 0);
	for(int i = 1; i <= m; i++) {
		cout << cnt[i];
		if(i != m) cout << " ";
	}
	
	return 0;
} 
