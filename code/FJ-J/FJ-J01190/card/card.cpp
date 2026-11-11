#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;

int n, m, a[N];
int cnt[M], last[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = n; i >= 1; i--)
		if (!last[a[i]]) last[a[i]] = i;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j <= n) {
			j = last[a[j]];
			cnt[a[j]]++;
			j++;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (i != 1) printf(" ");
		printf("%d", cnt[i]);
	}
	return 0;
}
