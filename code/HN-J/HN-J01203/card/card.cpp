#include <stdio.h>
#include <string.h>

int a[500000];
int b[500000];
int ans[300000];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	memset(ans, 0, sizeof(ans));
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", a+i), a[i]--;
	for (int i = 0; i < n; i++) {
		int* p = b;
		for (int j = i; j < n; j++) {
			for (int k = 0; k < p-b; k++) {
				if (b[k] == a[j]) {
					p = b+k;
					break;
				}
			}
			*p++ = a[j];
		}
		for (int i = 0; i < p-b; i++)
			if (b[i] < m)
				ans[b[i]]++;
	}
	for (int i = 0; i < m; i++)
		printf("%d ", ans[i]);
	return 0;
}

