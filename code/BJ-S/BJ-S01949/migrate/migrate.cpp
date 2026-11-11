#include<cstdio>
#include<set>
#include<algorithm>
using LL = long long;
const int N = 5005;
int n;
LL d;
LL a[2000005];
int nxt[N];
int g[N];
int f[N];
void work() {
	scanf("%d %lld", &n, &d);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	std::set<std::pair<LL, int> > s;
	for (int i = n; i >= 1; --i) {
		auto it = s.upper_bound({d + a[i], 1000000000});	
		if (it == s.begin()) {
			nxt[i] = -1;
		} else {
			nxt[i] = std::prev(it)->second;
		}
		s.insert({a[i], i});
	}
	LL ans = 0;
	for (int v = 1; v <= n; ++v) {
		int l = v;
		while (l > 1 && a[l] - a[l - 1] <= d)
			--l;
		f[v] = 0;
		for (int i = v - 1; i >= l; --i)
			f[i] = f[std::min(v, nxt[i])] + 1;
		g[v] = 1;
		for (int i = v - 1; i >= l; --i) {
			g[i] = 0;
			for (int p = std::max(i + 1, std::min(v, nxt[i]) - 2); p <= std::min(v, nxt[i]); ++p) {
				if (f[p] + 1 == f[i])
					g[i] += g[p];
			}
			g[i] = std::min(g[i], 3);
			if (g[i] == 2)
				++ans;
		}
	}
	printf("%lld\n", ans);
}
void work2() {
	scanf("%d %lld", &n, &d);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	if (n == 1) {
		puts("0");
		return ;
	}
	LL o = a[2] - a[1];
	if (d / o == 2) {
		printf("%d\n", std::max(0, n - 3));
	} else {
		puts("0");
	}
}
int main() {
	//freopen("std.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d %d", &c, &t);
	if (c <= 10) {
		while (t--)
			work();
	} else if (c == 11 || c == 12) {
		while (t--)
			work2();
	}
	return 0;
}