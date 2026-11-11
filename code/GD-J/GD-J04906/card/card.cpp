#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 500005
#define M 300005
#define coi const int &
#define pb push_back

int n, m;
int a[N], lst[M], ans[M];
vector < vector < int > > st;

void merge(coi x, coi y) {
	vector < int > res;
	int l1 = st[x].size(), l2 = st[y].size();
	int i = 0, j = 0;
	while (i < l1 && j < l2) {
		if (st[x][i] == st[y][j]) {
			res.pb(st[x][i]);
			++ ans[st[x][i]];
			++ i, ++ j;
		} else if (st[x][i] < st[y][j]) {
			++ ans[st[x][i]];
			res.pb(st[x][i ++]);
		} else {
			++ ans[st[y][j]];
			res.pb(st[y][j ++]);
		}
	}
	while (i < l1) {
		++ ans[st[x][i]];
		res.pb(st[x][i ++]);
	}
	while (j < l2) {
		++ ans[st[y][j]];
		res.pb(st[y][j ++]);
	}
	st[x] = res;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", & n, & m), st.assign(n + 2, {});
	for (int i = 1; i <= n; scanf("%d", & a[i ++]));
	for (int i = n, j; 1 <= i; -- i) {
		if (! lst[a[i]]) {
			lst[a[i]] = i;
		}
		j = lst[a[i]];
		while (j <= n) {
			if (lst[a[j]] ^ j) {
				continue ;
			}
			st[i].pb(a[j ++]);
		}
		sort(st[i].begin(), st[i].end());
		st[i].erase(unique(st[i].begin(), st[i].end()), st[i].end());
		merge(i, j);
	}
	for (int i = 1; i <= m; printf("%d ", ans[i ++]));
	puts("");
	return 0;
}
