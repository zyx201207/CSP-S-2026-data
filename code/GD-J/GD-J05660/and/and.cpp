#include <bits/stdc++.h>
using namespace std;
int n, m, ans, mx;
int a[2007];
int cnt[5];
bool vis[27];
void dfs(int k, int sm) {
	if(k > m) {
		ans = max(ans, sm);
		return;
	}	
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			dfs(k + 1, sm & a[i]);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if(m == 1) {
		for(int i = 1; i <= n; i++) ans = max(ans, a[i]);
		cout << ans;
		return 0;
	}
	if(m == 2) {
		for(int i = 1; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(m == n) {
		ans = 0x7fffffff;
		for(int i = 1; i <= n; i++) ans = ans & a[i];
		cout << ans;
		return 0;
	}
	if(mx <= 4) {
		for(int i = 1; i <= n; i++) cnt[a[i]]++;
		if(a[4] > m) {
			cout << 4;
			return 0;
		}
		if(a[3] > m) {
			cout << 3;
			return 0;
		}
		if(a[2] > m || a[2] + a[3] > m) {
			cout << 2;
			return 0;
		}
		if(a[1] > m || a[1] + a[3] > m) {
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	dfs(1, 0x7fffffff);
	cout << ans;
	return 0;
}
