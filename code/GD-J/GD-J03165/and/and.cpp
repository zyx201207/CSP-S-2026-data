#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m;
int a[N], num[N];
int res;

void dfs(int u, int id) {
	if (u == m) {
		int ans = num[0];
		for (int i = 1; i < m; i ++) ans &= num[i];
		res = max(res, ans);
		return ;
	}
	
	for (int i = id; i <= n - m + u + 1; i ++)
		num[u] = a[i], dfs(u + 1, i + 1);
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	if (n > 2000 && m != n - 1) {
		sort(a + 1, a + 1 + n);
		cout << a[n - m + 1];
	}
	dfs(0, 1);
	printf("%d", res);
	
	return 0;
} 
