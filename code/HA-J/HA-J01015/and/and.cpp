#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0;
long long a[100005], vis[100005] , z[100005];
void dfs(int s) {
	if (s == m) {
		int ans = z[0] and z[1];
		for (int i = 2; i < m; i++) {
			ans = ans and z[i];
		} if (ans > cnt) cnt = ans;
		return;
	} 
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0) {
			z[s] = a[i]; 
			vis[i] = 1; 
			dfs(s + 1);vis[i] = 0;
		} 
	}
}
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	} dfs(0);
	cout << cnt;
	return 0;
}
