#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], s[500005], ans[500005];
long long k = 0;
queue<int> q1;
void dfs(int x) {
	for (int i = 1; i <= k; i ++) {
		if(x == s[i]) {
			for (int j = i; j <= n; j ++) 
			k = i - 1;
			return;
		}
	}
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		q1.push(a[i]);
	}
	for (int i = 1; i <= n; i ++) {
		memset(s, 0, sizeof(s));
		k = 0;
		for (int j = 1; j <= i - 1; j ++) {
			q1.pop();
		}
		for (int j = 1; j <= n; j ++) {
			int x = q1.front();
			dfs(x);
			k ++;
			s[k] = x;
			q1.pop();
		}
		for (int j = 1; j <= k; j ++) {
			ans[s[j]] ++;
		}
		for (int i = 1; i <= n; i ++) {
			q1.push(a[i]);
		}
	}
	for (int i = 1; i <= m; i ++) {
		cout << ans[i] << " ";
	}
	return 0;
}
