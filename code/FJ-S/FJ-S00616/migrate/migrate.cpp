#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e6 + 10;

struct node {
	int u; mutable int k;
	node(int u = 0, int k = 0) : u(u), k(k) {}
	bool operator < (const node &rhs) const { return u < rhs.u; }
};

inline 
void insert(set<node> &s, node x) {
	auto it = s.lower_bound(x);
	if (it == s.end() || it->u != x.u) s.emplace(x);
	else it->k += x.k;
}

int n;

struct BIT {
	int c[MAXN];
	inline void clear() { for (int i = 1; i <= n; i++) c[i] = 0; }
	inline void add(int k, int x) { for (; k <= n; k += k & -k) c[k] += x; }
	inline int ask(int k) { int res = 0; for (; k; k &= k - 1) res += c[k]; return res; }
} t1, t2;

ll d, a[MAXN]; int p[MAXN];

inline 
ll solve() {
	ll res = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		for (; a[j] < a[i] - d; j++); p[i] = j;
	}
	set<node> s0[2], s1[2], s2[2];
	s0[0].emplace(1, 1); int tot = 0; t1.clear(), t2.clear();
	for (int i = 2; i <= n; i++) {
		if (p[i] == i) {
			s0[0].clear(), s0[1].clear(), tot = 0;
			for (auto x : s1[0]) t1.add(x.u, -x.k); s1[0].clear();
			for (auto x : s1[1]) t2.add(x.u, -x.k); s1[1].clear();
			for (auto x : s2[1]) t2.add(x.u, -x.k);
			s2[0].clear(), s2[1].clear();
		} else {
			auto insert_x = [&](int lst, int op, const node &x) -> void {
				if (x.u > lst + 2) {
					if (op) t2.add(x.u, x.k);
					insert(s2[op], x);
				} else if (x.u > lst + 1) {
					if (op) t2.add(x.u, x.k);
					else t1.add(x.u, x.k);
					insert(s1[op], x);
				} else {
					if (op) tot += x.k;
					insert(s0[op], x);
				}
			};
			for (int _ : { 0, 1 }) {
				auto &s = s2[_];
				for (; !s.empty(); ) {
					node x = *s.begin(); int op = _;
					if (x.u >= p[i]) break; s.erase(*s.begin());
					if (op) t2.add(x.u, -x.k);
					if (x.u >= p[i - 1] + 2) continue;
					if (x.u >= p[i - 1] + 1) { if (op) continue; op = 1; }
					int lst = x.u; x.u = i - 1, insert_x(lst, op, x);
				}
			}
			for (int _ : { 0, 1 }) {
				auto &s = s1[_];
				for (; !s.empty(); ) {
					node x = *s.begin(); int op = _;
					if (x.u >= p[i]) break; s.erase(*s.begin());
					if (op) t2.add(x.u, -x.k);
					else t1.add(x.u, -x.k);
					if (x.u >= p[i - 1] + 1) { if (op) continue; op = 1; }
					int lst = x.u; x.u = i - 1, insert_x(lst, op, x);
				}
			}
			for (int _ : { 0, 1 }) {
				auto &s = s0[_];
				for (; !s.empty(); ) {
					node x = *s.begin(); int op = _;
					if (x.u >= p[i]) break; s.erase(*s.begin());
					if (op) tot -= x.k;
					int lst = x.u; x.u = i - 1, insert_x(lst, op, x);
				}
			}
		}
		res += t1.ask(n) - t1.ask(p[i]) + tot + t2.ask(p[i]);
		auto it = s2[0].lower_bound(node(p[i] + 1));
		if (it != s2[0].end() && it->u == p[i] + 1) res += it->k;
		s0[0].emplace(i, 1);
	}
	return res;
}

int T;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	for (scanf("%*d%d", &T); T--; ) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		printf("%lld\n", solve());
	}
}
