#include <stdio.h>
#define maxn 500010
#define ll long long
#define ls(i) (i << 1)
#define rs(i) (i << 1 | 1)
int n, m, a[maxn];
struct node { int sum, len, tag; } tree[maxn << 2];
void pushup(int i) {
	tree[i].sum = tree[ls(i)].sum + tree[rs(i)].sum;
	tree[i].len = tree[ls(i)].len + tree[rs(i)].len;
}
void pushdown(int i) {
	if (tree[i].tag) {
		tree[ls(i)].sum += tree[ls(i)].len * tree[i].tag;
		tree[rs(i)].sum += tree[rs(i)].len * tree[i].tag;
		tree[ls(i)].tag += tree[i].tag;
		tree[rs(i)].tag += tree[i].tag;
		tree[i].tag = 0;
	}
}
void build(int i, int tl, int tr) {
	if (tl == tr) {
		tree[i].sum = a[tl];
		tree[i].len = 1;
		return ;
	}
	int tm = tl + tr >> 1;
	build(ls(i), tl, tm);
	build(rs(i), tm + 1, tr);
	pushup(i);
}
void update(int i, int tl, int tr, int l, int r, int v) {
	if (l > tr || r < tl) return ;
	if (l <= tl && tr <= r) {
		tree[i].sum += tree[i].len * v;
		tree[i].tag += v;
		return ; 
	}
	int tm = tl + tr >> 1;
	pushdown(i);
	update(ls(i), tl, tm, l, r, v);
	update(rs(i), tm + 1, tr, l, r, v);
	pushup(i);
}
int query(int i, int tl, int tr, int l, int r) {
	if (l > tr || r < tl) return 0;
	if (l <= tl && tr <= r) return tree[i].sum;
	int tm = tl + tr >> 1;
	pushdown(i);
	return query(ls(i), tl, tm, l, r) + query(rs(i), tm + 1, tr, l, r);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	build(1, 1, n);
	for (int i = 1, op, l, r, v; i <= m; i++) {
		scanf("%d %d %d", &op, &l, &r);
		if (op == 1) scanf("%d", &v), update(1, 1, n, l, r, v);
		else printf("%d\n", query(1, 1, n, l, r));
	}
	return 0;
}
