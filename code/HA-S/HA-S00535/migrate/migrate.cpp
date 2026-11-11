#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 5010;

int c, T, n;
LL a[N], d, cnt = 0;

inline LL Get (int x, int y) {
	LL now = x, dist = 0;
	while(now < y) {
		now = upper_bound (a + 1, a + n + 1, d + x) - a - 2;
		dist ++;
	}
	return dist;
}

inline bool dfs (LL now, LL goal, LL minn, LL tot, LL last) {
	if (tot > minn) return ;
	if (a[now] >= a[j]) {
		if (tot == minn) cnt ++;
		return ;
	}
	
	for (int i = now; i <= goal; i ++) {
		if (a[i] - a[last] <= d) dfs (i, goal, minn, tot + 1, i);
	}
	
	return ;
}

inline void solve () {
	scanf ("%d %lld", &n, &d);
	for (int i = 1; i <= n; i ++) scanf ("%lld", &a[i]);
	
	LL res = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			LL dist = Get(a[i], a[j]); cnt = 0;
			dfs (i, j, dist, 0, i);
			if (cnt == 2) res ++;
		}
	}
	
	printf ("%lld\n", res);
	return ;
}

int main() {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	
	scanf ("%d %d", &c, &T);
	while (T --) solve ();
}