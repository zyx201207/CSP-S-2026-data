#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const int maxm = 3e5 + 10;
int n, m;
int a[maxn], d[maxm], ans[maxm] = {0};
bool op[maxn];
struct node {
	int f, n;
} f[maxn];
void init() {
	for(int i = 0; i <= m; i++)d[i] = 0;
	for(int i = 1; i <= n; i++)f[i] = {i - 1, i + 1};
	f[n].n = -1;
	memset(op, 0, sizeof(op));
}
int main() {
	freopen("card5.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)scanf("%d", a + i);
	for(int i = 1; i <= n; i++) {
		init();
		f[0].n = i;
		f[i].f = 0;
		for(int j = i; j != -1; j = f[j].n) {
			if(d[a[j]] && !op[d[a[j]]]) {
				f[f[d[a[j]]].f].n = j;
				f[j].f = f[d[a[j]]].f;
				memset(op + d[a[j]], 1, j - d[a[j]]);
			}
			d[a[j]] = j;
		}
		for(int j = f[0].n; j != -1; j = f[j].n) {
			ans[a[j]]++;
		}
	}
	for(int i = 1; i <= m; i++)printf("%d ", ans[i]);
	return 0;
}
