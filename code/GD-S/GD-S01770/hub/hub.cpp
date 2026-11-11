#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
int tt, n, k, dep[N], dep2[N], cnt[N];
vector<int> e[N];
void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	for (auto v : e[u]) {
		if (v != fa) dfs(v, u);
	}
}
void ddfs(int u, int fa) {
	dep2[u] = dep2[fa] + 1;
	for (auto v : e[u]) {
		if (v != fa) ddfs(v, u);
	}
}
int calc(int s) {
	int res = 0;
	while (s) {
		res += s & 1;
		s >>= 1;
	}
	return res;
}
int btot = 0;
void dddfs(int u, int fa, int s) {
	if ((s & (1 << (u - 1))) && (fa == 0 || !(s & (1 << (fa - 1))))) btot++;
	for (auto v : e[u]) {
		if (v != fa) dddfs(v, u, s);
	}
}
void ddddfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	cnt[u] = min(cnt[u], dep[u] - 1);
	for (auto v : e[u]) {
		if (v != fa) ddddfs(v, u);
	}
}

void Main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		e[i].clear();
	}
	for (int i = 1; i < n; i++) {
//		puts("&&&");
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if (k == n) {
		puts("0");
		return;
	}
	if (k == 2) {
		int rans = n;
		int ans = n;
		for (int i = 1; i <= n; i++) {
			dfs(i, 0);
			for (int ii = i + 1; ii <= n; ii++) {
				ddfs(ii, 0);
				int res = 0;
				for (int iii = 1; iii <= n; iii++) {
					if (i == 2 && ii == 4) {
//						printf("&&&%d %d\n", iii, min(dep[iii], dep2[iii]) - 1);
					}
					res = max(res, min(dep[iii], dep2[iii]) - 1);
				}
				ans = min(ans, res);
//				printf("%d %d %d\n", i, ii, res);
			}
//			ans = min(ans, res);
		}
		rans = min(rans, ans);
		printf("%d\n", rans);
		return;
	}
	if (tt == 13 || tt == 14) {
		dfs(1, 0);
		int tot = 0;
		for (int i = 1; i <= n; i++) {
			tot = max(tot, dep[i]);
		}
		printf("%d\n", max(1, tot - k - 1));
		return;
	}
	int ans = n;
	for (int s = 1; s < (1 << n); s++) {
		if (calc(s) != k) continue;
		btot = 0;
		dddfs(1, 0, s);
		if (btot > 2) continue;
		memset(cnt, 127, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			if (s & (1 << (i - 1))) ddddfs(i, 0);
		}
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res = max(res, cnt[i]);
		}
//		printf("%d\n", res);
		ans = min(ans, res);
	}
	printf("%d\n", ans);
//	printf("%d\n", rand() % n + 1);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int tc;
	scanf("%d%d", &tt, &tc);
	while (tc--) Main();
	return 0;
}
