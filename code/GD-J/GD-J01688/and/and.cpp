#include <bits/stdc++.h>
using namespace std;
#define deb(n) cout << #n << " = " << n << '\n';
const int N = 2e5 + 10;
int n, m;
int a[N];
int path[N];
bool vis[N];
int mx = 0;
int idx = 0;
void dfs(int now) {
	if (now == m + 1) {
		int res = path[1];
		for (int i = 2; i <= m; i++) res &= path[i];
		mx = max(mx, res);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		path[++idx] = a[i];
		vis[i] = true;
		dfs(now + 1);
		vis[i] = false;
		idx--;
	}
}


int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int all = a[1];
	for (int i = 2; i <= n; i++) all &= a[i];
	if (n == 1) {
		cout << a[1];
	} else if (m == 1) {
		cout << a[n];
	} else if (m == 2) {
		int mx = 0;
		for (int i = 1; i <= n - 1; i++) mx = max(mx, a[n] & a[i]);
		cout << mx;
	} else if (m == n) {
		cout << all;
	} else if (a[n] < 4) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) cnt1++;
			if (a[i] == 2) cnt2++;
			if (a[i] == 3) cnt3++;
		} 
		if (cnt3) cnt3 += cnt1;
		if (cnt3 >= m) cout << 3;
		else cout << 2;
	} else if (n <= 20) {
		dfs(1);
		cout << mx;
	} else {
		int ans = a[n];
		for (int i = n - 1; i >= n - m + 1; i--) {
			deb(ans);
			ans &= a[i];
		}
		cout << ans;
	}
	return 0;
} 
