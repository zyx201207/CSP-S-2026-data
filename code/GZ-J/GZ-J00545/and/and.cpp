// GZ-J00545 ¶ÅÔóìÓ 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, m; 
int res[N];
int ans, maxn;
int instk[N];
vector<int> a(N);
inline void dfs(int step) {
	if(step == m) {
		maxn = res[0];
		for(int i = 0; i < m; i ++) {
			maxn = maxn & res[i];
		}
		ans = max(ans, maxn);
	}
	for(int i = 1; i <= n; i ++) {
		if(instk[i])continue;
		instk[i] = 1;
		res[step] = a[i];
		dfs(step + 1);
		instk[i] = 0;
	}
} 
inline bool check(int x) {
	while(true) {
		x /= 2;
		if(x % 2 != 0 && x != 1) {
			return false;
		}
		if(x == 1) return true;
	}
	return false;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	
	a.resize(n + 1);
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] == i-1) cnt ++;
	} 
	bool G = check(n);
	if(cnt == n && G) {
		cout << 0 << "\n";
		exit(0);
	}
	
	dfs(0);
	cout << ans << "\n";
	return 0;
}

