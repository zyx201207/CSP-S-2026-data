#include <bits/stdc++.h>
using namespace std;

int n, m, a[500010], c[500010], ans[500010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) c[j] = 0;
		stack<int> stk;
		for (int j = i; j <= n; j++) {
			while (c[a[j]] && !stk.empty()) {
				int x = stk.top(); stk.pop();
				c[x]--;
				if (x == a[j]) break;
			}
			c[a[j]]++;
			stk.push(a[j]);
		}
		while (!stk.empty()) {
			ans[stk.top()]++; stk.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}

