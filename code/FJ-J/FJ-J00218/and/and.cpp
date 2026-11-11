#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
int n, m;
long long a[maxn], all, ans, b[maxn];
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if(i == 0) all = a[i];
		else all &= a[i];
	}
	sort(a, a + n, cmp);
	if(n == m) {
		printf("%lld", all);
		return 0;
	}
	if(m == 1) {
		printf("%lld", a[0]);
		return 0;
	}
	if(a[0] < 4) {
		if(a[m] != 1) printf("%lld", a[m]);
		else {
			int i = 0, cnt1, cnt2, cnt3;
			while(a[i] > 2) i++;
			cnt1 = i;
			while(a[i] > 1) i++;
			cnt2 = i - cnt1;
			while(a[i] > 0) i++;
			cnt3 = i - cnt1 - cnt2;
			if(cnt1 + cnt3 >= m) printf("1");
			else printf("0");
		}
		return 0;
	}
	if(n < 2000 && n > 20) {
		for(int i = 0; i < 21; i++) {
			for(int j = i + 1; j < 21; j++) {
				if(a[i] & a[j] > ans) {
					ans = a[i] & a[j];
				}
			}
		}
		printf("%lld", ans);
		return 0;
	}
	if(m == n - 1) {
		b[0] = a[1];
		for(int i = 1; i < n; i++) b[i] = a[0];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(j != i) b[j] = b[j] * a[i];
			}
		}
		sort(b, b + n, cmp);
		printf("%lld", b[0]);
		return 0;
	}
	if(n <= 20) {
		
		return 0;
	}
	for(int i = 0; i < m; i++) {
		if(i == 0) ans = a[i];
		else ans = ans & a[i];
	}
	printf("%lld", ans);
	return 0;
}
