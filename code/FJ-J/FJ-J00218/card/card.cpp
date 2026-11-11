#include <bits/stdc++.h>
using namespace std;
bool flag = 1;
int m, n, a[500005], ans[300005], cnt1, cnt2;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if(i) {
			if(a[i] < a[i - 1]) flag = 0;
		}
	}
	if(flag) {
		int l = 0, cnt = 0;
		for(int i = 1; i <= m; i++) {
			for(int j = l; a[j] == i; j++) {
				cnt++;
			}
			printf("%d ", cnt);
			l = cnt;
		}
		return 0;
	}
	if(m == 2) {
		for(int i = 0; i < n; i++) {
			if(a[i] == 1) cnt1++;
			if(a[i] == 2) cnt2++;
		}
		if(a[n - 1] == 1) printf("%d %d", n, cnt2);
		else printf("%d %d", cnt1, n);
		return 0;
	}
	ans[a[n - 1]] = n;
	return 0;
}
