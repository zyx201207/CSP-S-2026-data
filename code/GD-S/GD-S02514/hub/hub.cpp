#include<bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = (l) ; i <= (r) ; i ++)
#define per(i, l, r) for (int i = (r) ; i >= (l) ; i --)

using ll = long long;

const int N = 2e5 + 10;

int n, k;

vector < int > e[N];

int dis[N];

void dfs (int p, int f, int d) {
	dis[p] = d;

	for (auto t : e[p]) {
		if (t == f) continue;

		dfs (t, p, d + 1);
	}
}

int dis2[N];

void dfs2 (int p, int f, int d) {
	dis2[p] = d;

	for (auto t : e[p]) {
		if (t == f) continue;

		dfs2 (t, p, d + 1);
	}
}

void solve () {
	cin >> n >> k;

	rep (i, 2, n) {
		int u, v; cin >> u >> v;
		e[u].push_back (v);
		e[v].push_back (u);
	}

}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);

	int c, t = 1;
	cin >> c >> t;
	while (t --) solve ();
}