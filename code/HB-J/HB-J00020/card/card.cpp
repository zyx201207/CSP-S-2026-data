#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5+10;
int a[N];
int cnt[N], ans[N];
int x[N], tot = 0;
int n, m;

bool A () {
	for (int i = 2; i <= n; i++) {
		if (a[i] < a[i-1]) return false;
	}
	return true;
}

signed main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &x[i]);
	if (A()) {
		for (int k = 1; k <= n; k++) {
			for (int i = k; i <= n; i++) {
				cnt[x[i]] = 1;
			}
			for (int i = 1; i <= m; i++) {
				if (cnt[i] == 1) {
					ans[i]++;
				}
				cnt[i] = 0;
			}
		}
		for (int i = 1; i <= m; i++) {
			printf("%lld ", ans[i]);
		}
		return 0;
	}
		
	for (int k = 1; k <= n; k++) {
		for (int i = k; i <= n; i++) {
			int tmp = -1;
			for (int j = 1; j <= tot; j++) {
				if (a[j] == x[j]) {
					tmp = i;
					break;
				}
			}
			if (tmp == -1) {
				a[++tot] = x[i];
				cnt[x[i]]++;
			}
			else {
				for (int j = tmp; j <= tot; j++) {
					cnt[x[j]]--;
					a[j] = -1;
				}
				tot = tmp;
				a[++tot] = tmp;
				//for (int j = tot; j >= 2; j--)
				//	a[j] = a[j-1];
				//a[1] = x[i];
			}
		
		for (int i = 1; i <= m; i++) {
			if (cnt[i] >= 1) {
				ans[i]++;
			}
		}
		for (int i = 1; i <= tot; i++) a[i] = 0;
		tot = 0;
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld ", ans[i]);
	}
}
	return 0;
}
