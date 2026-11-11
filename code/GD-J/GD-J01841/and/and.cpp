#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, m;
ll a[N];


ll ans = 0;
void dfs(int now, int cnt, ll val, bool vis[]) {
	if(cnt == m) {
		ans = max(ans, val);
		return ;
	}
	for(int i = now; i <= n;i++) {
		if(!vis[i]) {
			vis[i] = 1;
			int nval = val & a[i];
			dfs(i + 1, cnt + 1, nval, vis);
			vis[i] = 0;
		}
	}
}

void solve() {
	vector<int> e[35][2];
	for(int i = 1;i <= n;i++) {
		for(int j = 0; j <= 30;j++) {
			e[j][(a[i] >> j) & 1].push_back(a[i]); 
		}
	}
	ll ans = 0;
	for(int i = 0; i <= 30;i++) {
		if(e[i][1].size() >= m) {
			ll now = (1ll << 31) - 1;
			for(int j = 0; j < e[i][1].size();j++) {
				now &= e[i][1][j];
			}
			ans = max(ans, now);
		}
		if(e[i][0].size() >= m) {
			ll now = (1ll << 31) - 1;
			for(int j = 0; j < e[i][0].size();j++) {
				now &= e[i][0][j];
			}
			ans = max(ans, now);
		}
		ll now = (1ll << 31) - 1;
		for(int j = 0; j < e[i][1].size();j++) {
			now &= e[i][1][j];
		}
		for(int j = 0; j < e[i][0].size();j++) {
			now &= e[i][0][j];
		}
		ans = max(ans, now);
	}
	ll maxx = 0;
	for(int i = 1;i <= n;i++) {
		maxx = max(maxx, a[i]);
	}
	ans = min(ans, maxx);
	ll sumn = (1ll << 31) - 1;
	for(int i = 1; i <= n;i++) {
		sumn &= a[i];
	}
	cout << max(sumn, ans);
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i]; 
	}
	if(n <= 20) {
		bool vis[25] = {};
		dfs(1, 0, (1ll << 31) - 1, vis);
		cout << ans;
		return 0;
	}
	else if(m == 1) {
		int maxx = 0;
		for(int i = 1;i <= n;i++) {
			maxx = max(1ll * maxx, a[i]);
		} 
		cout << maxx;
		return 0;
	}
	else if(m == 2 && n <= 20000) {
		int maxx = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1; j <= n;j++) {
				if(i == j) continue;
				maxx = max(1ll * maxx, a[i] & a[j]); 
			}
		}
		cout << maxx;
		return 0;
	}
	else if(m == n) {
		int maxx = a[1];
		for(int i = 2;i <= n;i++) {
			maxx &= a[i];
		}
		cout << maxx;
		return 0;
	}
	else {
		solve();
	}
	return 0; 
} 
