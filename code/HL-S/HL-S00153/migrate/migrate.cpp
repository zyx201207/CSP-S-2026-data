#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e6;

int testcase, test, n, nxt[N + 1], lst[N + 1], cnxt[N + 1], clst[N + 1];
ll d, x[N + 1];
int fa[N + 1], siz[N + 1], cnt[N + 1];

int get_fa(int node) {
	if (fa[node] == node)
		return node;
	else
		return fa[node] = get_fa(fa[node]);
}

inline void merge(int u, int v) {
	u = get_fa(u);
	v = get_fa(v);
	if (u == v)
		return;
	siz[u] += siz[v];
	fa[v] = u;
}

int use[N + 1], now[N + 1], pre[N + 1], suf[N + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> testcase >> test;
	while (test--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			cnxt[i] = clst[i] = 0;
		}
		int to = 1;
		for (int i = 1; i <= n; i++) {
			to = max(to, i);
			while (to + 1 <= n && x[to + 1] - x[i] <= d)
				to++;
			nxt[i] = to;
			cnxt[nxt[i]]++;
		}
		to = n;
		for (int i = n; i >= 1; i--) {
			to = min(to, i);
			while (to - 1 >= 1 && x[i] - x[to - 1] <= d)
				to--;
			lst[i] = to;
			clst[lst[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
			siz[i] = 1;
			cnt[i] = 0;
		}
		for (int i = 1; i <= n; i++)
			if (lst[nxt[i]] == i)
				merge(i, nxt[i]);
		for (int i = 1; i <= n; i++)
			if (nxt[lst[i]] == i)
				merge(i, lst[i]);
		for (int i = 1; i <= n; i++)
			now[i] = use[i] = 0;
		for (int i = 1; i <= n; i++) {
			now[get_fa(i)] += cnxt[i] - (nxt[i] == i);
			pre[i] = now[get_fa(i)];
			use[get_fa(i)] = i;
		}
		for (int i = 1; i <= n; i++)
			now[i] = use[i] = 0;
		for (int i = n; i >= 1; i--) {
			now[get_fa(i)] += clst[i] - (lst[i] == i);
			suf[i] = now[get_fa(i)];
			use[get_fa(i)] = i;
		}
		ll ans = 0;
		for (int i = 1; i < n; i++) {
			int u = i, v = i + 1;
			ll L = cnxt[v] - (nxt[u] == v) - (nxt[v] == v);
			if (lst[u] != u && nxt[lst[u]] == v)
				L += pre[lst[u]];
			ll R = clst[u] - (lst[v] == u) - (lst[u] == u);
			if (nxt[v] != v && lst[nxt[v]] == u)
				R += suf[nxt[v]];
			ans += L * R;
		}
		cout << ans << '\n';
	}
	return 0;
}
