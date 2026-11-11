#include <bits/stdc++.h>

using namespace std;

int n, m, a[500001], s[300001], p[300001], t[300001], top;
bool b[300001];

int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		top = 0;
		memset(b, false, sizeof(b));
		memset(p, 0, sizeof(p));
		for (int j = i; j <= n; j++) {
			if (p[a[j]] != 0) {
				top = p[a[j]];
				continue;
			}
			t[++top] = a[j];
			p[a[j]] = top;
		}
		for (int j = 1; j <= top; j++) {
			if (b[t[j]] == false)
				s[t[j]]++, b[t[j]] = true;
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", s[i]);
	printf("\n"); 
	return 0;
}
