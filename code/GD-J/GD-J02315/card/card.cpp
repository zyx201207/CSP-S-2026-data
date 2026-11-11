#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, a[500005], lst[300005], st[500005], top, f[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			lst[j] = 0;
		top = 0;
		for (int j = i; j <= n; j++) {
			if (lst[a[j]] > top)
				lst[a[j]] = 0;
			if (!lst[a[j]]) {
				st[++top] = a[j];
				lst[a[j]] = top;
			} else {
				for (int r = lst[a[j]] + 1; r <= top; r++)
					lst[st[r]] = 0;
				top = lst[a[j]];
			}
		}
		for (int j = 1; j <= top; j++)
			f[st[j]]++;
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", f[i]);
	return 0;
}
