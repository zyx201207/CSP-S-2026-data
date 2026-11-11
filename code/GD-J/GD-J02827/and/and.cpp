#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m, a[N], maxn;

void dfs (int cnt, int id, int t){
	if (cnt == m){
		maxn = max(maxn, t);
		return;
	}
	for (int i = id + 1; i <= n; i++) dfs(cnt + 1, i, t & a[i]);
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n - m + 1; i++) dfs(1, i, a[i]);
	cout << maxn;
	return 0;
}
