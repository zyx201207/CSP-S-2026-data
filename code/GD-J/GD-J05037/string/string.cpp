#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, a[N];
char ch[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char s[3];
		scanf("%d%s", &a[i], s);
		ch[i] = s[0];
	}
	int l = 1, r = n, sl = 0, sr = 0;
	long long ans = 0;
	while (l < r) {
		if (ch[l] != ch[r]) {
			ans += min(a[l] - sl, a[r] - sr);
		}
		if (a[l] - sl > a[r] - sr) {
			sl += (a[r] - sr), r--, sr = 0;
		} else if (a[l] - sl == a[r] - sr) {
			l++, r--, sl = 0, sr = 0;
		} else if (a[l] - sl < a[r] - sr) {
			sr += (a[l] - sl), l++, sl = 0;
		}
	}
	printf("%lld\n", ans);
	
	return 0; 
}
