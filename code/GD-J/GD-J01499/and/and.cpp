#include<bits/stdc++.h>

using namespace std;

const int maxn = 200006;

int n, m, ans = 0;
int a[maxn], used[maxn];

void dfs(int cur, int val, int used[]) {
	if(cur == m) {
		ans = max(ans, val);
	}
	for(int i = 1; i <= n; i++) {
		bool ok = true;
		for(int j = 0; j < cur; j++) {
			if(used[j] == a[i]) {
				ok = false;
			}
		}
		if(ok) {
			used[cur] = a[i];
			dfs(cur + 1, val & a[i], used);
			used[cur] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		used[0] = a[i];
		dfs(1, a[i], used);
	}
	cout << ans;
	return 0;
}
