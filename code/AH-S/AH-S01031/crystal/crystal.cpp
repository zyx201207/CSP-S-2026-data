/*CN*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 5e5 + 5;
ll n, m, a[N], ans = LLONG_MIN, f[N], Aflag, Bflag, sum[N];
void pian12(int cnt, int pre) { //test No.1.2-------Not much problem
	if (cnt > m) {
		for (int i = 1; i <= n; i++) {
			f[a[i] + 20]++;
		}
		for (int i = 0; i <= 40; i++) {
			ans = max(ans, f[i]);
			f[i] = 0;
		}
		return;
	}
	for (int i = pre; i <= n; i++) {
		a[i]++;
		pian12(cnt+1, i);
		a[i]--;
	}
	return;
}
void specialB() {
	ll d = a[2] - a[1];
	if (m == 0) {
		printf("0");
		return;
	}
	if (m < d) {
		printf("1");
		return;
	}
	for (int i = n; i >= 2; i--) {
		if (i * (i - 1) * d / 2 <= m) {
			printf("%d", i);
			return ;
		}
	}
	return;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= (int)n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	if (n <= 5 && m <= 10) {//test No.1-2
		pian12(1, 1);
		printf("%lld", ans);
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			Bflag = 1;
			break;
		}
	}
	if (Bflag == 0) { //test No.16-18 (Special B)
		specialB();
		return 0;
	}
	for (int i = n; i >= 1; i--) {
		if ((ll)(i - 1) * a[i] - sum[i - 1] <= m) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 10
0 1 2 3 4

5 20
1 3 5 7 9
*/
