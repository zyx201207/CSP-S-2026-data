#include <bits/stdc++.h>

using namespace std;

#define N 200005
#define coi const int &

int n, m;
int a[N], ans;

bool check(coi res) {
	int cnt = 0;
	for (int i = 1; i <= n; cnt += ((a[i ++] & res) == res));
	return m <= cnt;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", & n, & m);
	for (int i = 1; i <= n; scanf("%d", & a[i ++]));
	for (int i = 29; 0 <= i; -- i) {
		int dt = 1 << i;
		if (check(ans + dt)) {
			ans += dt;
		}
	}
	printf("%d\n", ans);
	return 0;
}
