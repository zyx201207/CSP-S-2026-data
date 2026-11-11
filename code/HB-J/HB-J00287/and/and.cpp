#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, m, a[200005], vis[200005], id[200005], k;

bool gt(int x) {
	return x & (1 << k);
}

bool cmp(int a, int b) {
	return vis[a] < vis[b];
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		id[i] = i;
	}
	for (k = 30; k >= 0; k--) {
		int nw = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] != INF) nw += gt(a[i]);
		}
		if (nw < m) continue;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == INF || !gt(a[i])) vis[i] = INF;
			else vis[i] = k;
		}
	}
	sort(id + 1, id + n + 1, cmp);
	int ans = a[id[1]];
	for (int i = 2; i <= m; i++) ans &= a[id[i]];
	cout << ans;
	return 0;
}
/*
3 15 12 12
0011
1111
1100
1100

7 4 3 1
111
100
011
001

12
*/
