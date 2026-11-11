#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;
int n, m, a[N], f[M], ans[M];
stack<int> st;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[j] = false;
		}
		for (int j = i; j <= n; j++) {
			if (f[a[j]]) {
				while (!st.empty() && st.top() != a[j]) f[st.top()] = false, st.pop();
			} else {
				st.push(a[j]);
				f[a[j]] = true;
			}
		}
		while (!st.empty()) ans[st.top()]++, st.pop();
	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
