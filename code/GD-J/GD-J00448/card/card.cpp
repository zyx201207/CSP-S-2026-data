#include <bits/stdc++.h>
using namespace std;

const int N = 501000;
int n, m, a[N], ans[N];
bool b[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	bool ok = true;
	for (int i = 1; i < n; i++) if (a[i] > a[i + 1]) {
		ok = false;
		break;
	}
	if (ok) {
		for (int i = 1; i <= n; i++)
			if (a[i] != a[i + 1]) ans[a[i]] = i;
		for (int i = 1; i <= m; i++) {
			printf("%d ", ans[i]);
		}
		puts("");
		return 0;
	}
	if (m == 1) {
		printf("%d\n", n);
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1 && a[n] == 1) {
				ans[1] += 1;
			} else if (a[i] == 2 && a[n] == 2) {
				ans[2] += 1;
			} else {
				ans[1] += 1;
				ans[2] += 1;
			}
		}
		printf("%d %d\n", ans[1], ans[2]);
		return 0;
	}
	stack<int> stk;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (b[a[j]]) {
				while (stk.top() != a[j]) {
					b[stk.top()] = false;
					stk.pop();
				}
				stk.pop();
			}
			stk.push(a[j]);
			b[a[j]] = true;
		}
		while (!stk.empty()) {
			ans[stk.top()] += 1;
			b[stk.top()] = false;
			stk.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}
