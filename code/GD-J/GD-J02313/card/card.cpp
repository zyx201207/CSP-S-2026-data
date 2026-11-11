#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005], s[500005], top, f[300005], flag, pos[300005];
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		if (pos[a[i]] == 0) pos[a[i]] = i;
		if (a[i-1] > a[i]) flag = 1;
	}
	for (int i = 1; i <= n; i++) {
		memset (s, 0, sizeof(s));
		memset (f, 0, sizeof(f));
		for (int j = i; j <= n; j++) {
			if (f[a[j]] == 0) s[++top] = a[j], f[a[j]] = top;
			else while (s[top] != a[j]) f[s[top--]] = 0;
		}
		for (int j = 1; j <= top; j++) ans[s[j]]++;
	}
	for (int i = 1; i <= m; i++)
		printf ("%d ", ans[i]);
	return 0;
}
