#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5;
int n, m, ans = 0, mx = 0;
int a[MAX_N];
bool cmp(int x, int y) {
	return x < y;
}
void dfs (int pos, int num) {
	if (pos >= m) return;
	for (int i = 1; i <= n; i++) {
		if (max(num, num & a[i]) > max(num, a[i] & a[i+1])) {
			dfs(pos+1, num & a[i]);
		} else {
			dfs(pos+1, a[i] & a[i+1]);
		}
	}
	ans = max(ans, num);
}
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1, cmp); 
	dfs(0,a[1]);
	cout << ans;
	return 0;
}
