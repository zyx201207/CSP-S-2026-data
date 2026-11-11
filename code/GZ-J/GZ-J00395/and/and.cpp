//GZ-J00395  贵阳市第三实验中学  闫张玴
#include <bits/stdc++.h> 
using namespace std;
#define int long long
const int N = 2e5+10;
int n, m, ans, sumn=INT_MAX;
int a[N];
bool f;

void dfs(int k, int ch, int tot) {
	if(m - ch > n-k+1) return;
	if(ch == m) {
		ans = max(tot, ans);
		return;
	}
	if(k == n+1) {
		return;
	}
	int t = tot&a[k];
	dfs(k+1, ch, tot);
	dfs(k+1, ch+1, t);
}

void dt(int k, int ch, int tot) {
	if(k == n+1) {
		ans = max(ans, tot);
		return;
	}
	int t = tot&a[k];
	if(ch == 1) dfs(k+1, ch, t);
	else {
		dfs(k+1, ch+1, tot);
		dfs(k+1, ch, t);
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i <= n; i++) {
		cin >> a[i];
	}
	if(n == m) {
		cout << sumn;
		return 0;
	}
	if(m == n-1) {
		dt(1, 0, INT_MAX);
		cout << ans;
		return 0;
	}
	dfs(1, 0, INT_MAX);
	cout << ans;
	return 0;
}
