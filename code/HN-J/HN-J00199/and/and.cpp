#include <bits/stdc++.h>
using namespace std;

int n, m;
long long maxn;
long long ans;
long long mem[200005];
long long a[200005];

void dfs(long long a1, long long a2, long long cnt) {
	if(cnt == m) {
		ans = max(ans, a2);
		return;
	}
	
	for(int i = a1 + 1; i <= n; i ++) {
		dfs(i, a[i] & a2, cnt + 1);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	memset(mem, -1, sizeof(mem));
	long long sum;
	cin >> n >> m;
	for(int i = 1; i <= n - m; i ++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	
	if(m == 1) cout << maxn;
	else {
		for(int i = 1; i <= n - m; i ++) {
			dfs(i, a[i], 1);
		}
		cout << ans;
	}
	
	return 0;
} 
