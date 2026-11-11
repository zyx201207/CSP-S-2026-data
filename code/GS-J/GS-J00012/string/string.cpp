#include<bits/stdc++.h>
using namespace std;

int n, top1 = 0, top2 = 0;
long long len = 0LL, ans = 0LL, a[200010], b[200010], c[200010];
char s[200020], sb[200020], sc[200020];

int main() {
	//Trick||Treat!
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %c", &a[i], &s[i]);
		len += a[i];
	}
	len /= 2;
	long long le = len;
	while (le) {
		top1++;
		if (a[top1] > le) {
			b[top1] = le;
			sb[top1] = s[top1];
			a[top1] -= le;
			le = 0;
			break;
		}else {
			b[top1] = a[top1];
			sb[top1] = s[top1];
			le -= a[top1];
			a[top1] = 0;
		}
	}
	le = len;
	while (le) {
		top2++;
		if (a[n - top2 + 1] > le) {
			c[top2] = le;
			sc[top2] = s[n - top2 + 1];
			a[n - top2 + 1] -= le;
			le = 0;
			break;
		}else {
			c[top2] = a[n - top2 + 1];
			sc[top2] = s[n - top2 + 1];
			le -= a[n - top2 + 1];
			a[n - top2 + 1] = 0;
		}
	}	
	for (int i = 1, j = 1; i <= top1 && j <= top2;) {
		if (sb[i] != sc[j]) {
			if (b[i] > c[j]) {
				ans += c[j];
				b[i] -= c[j];
				c[j] = 0;
				j++;
			}else if (b[i] < c[j]) {
				ans += b[i];
				c[j] -= b[i];
				b[i] = 0;
				i++;
			}else {
				ans += b[i];
				b[i] = c[j] = 0;
				i++, j++;
			}
		}
		if (sb[i] == sc[j]) {
			if (b[i] > c[j]) {
				b[i] -= c[j];
				c[j] = 0;
				j++;
			}else if (b[i] < c[j]) {
				c[j] -= b[i];
				b[i] = 0;
				i++;
			}else {
				b[i] = c[j] = 0;
				i++, j++;
			}			
		}
	}
	printf("%lld", ans);
}
