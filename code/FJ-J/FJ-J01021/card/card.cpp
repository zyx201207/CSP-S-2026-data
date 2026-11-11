#include <cstdio>
int n, m, top, a[500005], nxt[500005], lst[300005], ans[300005];
struct stuck{
	int id, num, nxt;
} st[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		nxt[lst[a[i]]] = i, lst[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		while (top != 0 && st[top].nxt < i && st[top].num != a[i]) --top;
		if (top) {
			ans[a[i]] += i - st[top].id;
		} else ans[a[i]] += i;
		if (nxt[i]) st[++top].id = i, st[top].num = a[i], st[top].nxt = nxt[i];
	}
	for (int i = 1; i <= m; ++i) {
		if (a[n] != i) printf("%d ", ans[i]);
		else printf("%d ", n); 
	}
	return 0;
}
