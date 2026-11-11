#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t;
int a[2000010];
int n;
long long d;

int zdl(int x, int y) {
	int sum = 1;
	int l = x;
	for(int i = x + 1; i <= y; i++) {
		if(a[i] - a[l] > d) {
			sum++;
			l = i;
		}
	}
	return sum;
}

bool vis[2000010];
int k, ans;

void dfs(int x, int y, int step) {
	if(step > k || ans > 2) return;
	if(x == y && step == k) {
		ans++;
		return;
	}
	for(int i = x + 1; i <= y; i++) {
		if(!vis[i] && a[i] - a[x] <= d) {
			vis[i] = true;
			dfs(i, y, step + 1);
			vis[i] = false;
		}
	}
	return;
}

bool check(int x, int y) {
	if(a[x + 1] - a[x] > d || a[y] - a[y - 1] > d) return false;
	k = zdl(x, y);
	ans = 0;
	dfs(x, y, 0);
	if(ans == 2) return true;
	return false;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int anss = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(check(i, j)) {
					anss++;
				}
			}
		}
		cout << anss << '\n';
	}

	return 0;
}
