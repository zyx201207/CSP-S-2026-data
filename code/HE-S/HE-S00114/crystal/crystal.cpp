#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[500010];

bool check(long long x) {
	long long y = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < x) {
			y += x - a[i];
		}
	}
	if (y <= m) {
		return true;
	} else {
		return false;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	long long cnt = -1 << 30;
	for (int i = 1; i <= n; i++)
		cnt = max(cnt, a[i]);
//	printf("%lld", cnt);


	long long L = -1e12 - 1, R = 1e12 + 1;

	while (L + 1 < R) {
		long long M = (L + R) / 2;
//		printf("L == %lld R == %lld M == %lld\n", L, R, M);
		if (check(M)) {
			L = M;
		} else {
			R = M;
		}
		if (L >= cnt) {
			break;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] <= L)
			++ans;
	printf("%d\n", ans);
//	printf("Time : %d", clock());
	return 0;
}




