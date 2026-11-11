#include<bits/stdc++.h>
using namespace std;
const int N=2000050;
int T, n, m, i, j, k, l, r, x, y, mid, v[N], f[N], ans, p;
vector<int> z[N];
void dfs(int k, int last, int s) {
	if (v[k] == s+1) {
		f[k] = 1;
		return;
	}
	int flag = 0;
	for (auto y : z[k]) {
		if (y == last) continue;
		flag++, dfs(y, k, s), f[k] = max(f[k], f[y]);
	}
	if (!f[k]) return;
	if (flag > 1) f[k] = 0;
	f[k]++, p++;
	printf("f:%d %d\n", k, f[k]);
	ans = max(ans, f[k]-1);
}
int check(int k) {
	if (k > v[1]) return true;
	memset(f, 0, sizeof(f));
	ans = p = 0;
	dfs(1, 0, k);
	printf("ans:%d %d %d\n", k, p, ans);
	if (p-ans <= m) return true;
	return false;
}
void init(int k, int last) {
	v[k] = 1;
	for (auto y : z[k]) {
		if (y == last) continue;
		init(y, k), v[k] = max(v[k], v[y]+1);
	}
}
int main() {
	scanf("%*d%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (i=1; i<=n; i++) z[i].clear();
		for (i=1; i<n; i++) scanf("%d%d", &x, &y), z[x].push_back(y), z[y].push_back(x);
		if (m >= n) {
			printf("0\n");
			continue;
		}
		l = 1, r = n;
		init(1, 0);
		while (l < r) {
			mid = l+r>>1;
			if (check(mid)) r = mid;
			else l = mid+1;
		}
		printf("%d\n", l);
	}
	return 0;
}

