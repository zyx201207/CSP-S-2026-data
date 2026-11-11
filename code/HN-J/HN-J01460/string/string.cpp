/*
期望得分：100pts 
*/ 
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2e5 + 7;

struct info {
	ll num;
	char s;
} a[N];

int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].s;
	}
	int L = 1, R = n;
	ll ans = 0;
	while (L <= R) {
		assert(L <= n && 1 <= R); 
		if (a[L].s != a[R].s) ans += min(a[L].num, a[R].num);
		if (a[L].num == a[R].num) ++L, --R;
		else if (a[L].num > a[R].num) {
			a[L].num -= a[R].num, --R;
		} else {
			a[R].num -= a[L].num, ++L;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

