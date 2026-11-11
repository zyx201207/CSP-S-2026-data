#include <bits/stdc++.h>

using namespace std;

const int N = 500010, M = 300010;

int n, m, a[N], c[M], f[M];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), c[a[i]] = i;
	for (int i = 1; i <= n; i++){
		int x = i;
		while (x <= n)
			++f[a[x]], x = c[a[x]] + 1;
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", f[i]);
	printf("\n");
	return 0;
}