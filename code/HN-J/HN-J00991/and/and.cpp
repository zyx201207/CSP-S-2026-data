#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m, ans1 = 0, ans2 = 0;
struct node {
	int v = 0;
	int l = 0;
} a[maxn];
bool cmp1(node a, node b) {
	if(a.l == b.l)return a.v > b.v;
	return a.l > b.l;
}
bool cmp2(node a, node b) {
	return a.v > b.v;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)scanf("%d", &a[i].v), a[i].l = __builtin_popcount(a[i].v);
	sort(a, a + n, cmp1);
	ans1 = a[0].v;
	for(int i = 0; i < m; i++) {
		ans1 &= a[i].v;
	}
	sort(a, a + n, cmp2);
	ans2 = a[0].v;
	for(int i = 0; i < m; i++) {
		ans2 &= a[i].v;
	}
	printf("%d", max(ans1, ans2));
	return 0;
}
