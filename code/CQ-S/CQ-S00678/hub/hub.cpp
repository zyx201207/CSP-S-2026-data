#include <stdio.h>
#define maxn 100010
int n, fa[maxn], siz[maxn];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return ;
	if (siz[x] < siz[y]) x ^= y ^= x ^= y;
	siz[x] += siz[y], fa[y] = x;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	return 0;
}
