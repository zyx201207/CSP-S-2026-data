#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[200005], maxn, tmp, n, m;

void dfs(int cur, int cnt, ll ans) {
	if(cnt == m) {
		maxn = max(maxn, ans);
		return ;
	}	
	if(cur > n) return ;
	if(cnt == 0) dfs(cur + 1, cnt + 1, a[cur]);
	else dfs(cur + 1, cnt + 1, ans & a[cur]);
	dfs(cur + 1, cnt, ans);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
		if(i == 1) tmp == a[i];
		else tmp &= a[i];
	}
	if(m == 1) {
		cout << maxn;
		return 0;
	} else if(m == n) {
		cout << tmp;
		return 0;
	}
	maxn = 0;
	dfs(1, 0, 0);
	cout << maxn << '\n';

	return 0; 
} 
