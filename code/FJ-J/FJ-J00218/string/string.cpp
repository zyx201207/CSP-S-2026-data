#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
int n;
bool f;
long long minl, maxl, ans;
struct strd {
	long long a;
	char c;
} s[maxn], last;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld %c", &s[i].a, &s[i].c);
	}
	last.c = 'F';
	for(int i = 0, j = n - 1 - i; i < j; ) {
		minl = min(s[i].a, s[j].a);
		maxl = s[i].a + s[j].a - minl;
		f = minl == s[i].a ? 1 : 0;
		if(s[i].c != s[j].c) ans += minl;
		last.a = maxl - minl;
		//printf("%lld %c %c %c\n", ans, last.c, s[i].c, s[j].c);
		if(last.a == 0) {
			i++;
			j--;
			continue;
		}
		if(f) {
			last.c = s[i].c;
			//printf("%lld %c %c %c\n", ans, last.c, s[i].c, s[j].c);
			j--;
			if(i >= j) break;
			while(last.a > s[j].a && i < j) {
				if(last.c != s[j].c) ans += last.a - s[j].a;
				last.a -= s[j].a;
				j--;
			}
			if(i >= j) break;
			if(last.c != s[j].c) ans += s[j].a - last.a;
			s[j].a -= last.a;
			i++;
		}
		else {
			last.c = s[j].c;
			//printf("%lld %c %c %c\n", ans, last.c, s[i].c, s[j].c);
			i++;
			if(i >= j) break;
			while(last.a > s[i].a && i < j) {
				if(last.c != s[i].c) ans += last.a - s[i].a;
				last.a -= s[i].a;
				i++;
			}
			if(i >= j) break;
			if(last.c != s[i].c) ans += s[i].a - last.a;
			s[i].a -= last.a;
			j--;
		}
		//printf("%lld %c %c %c\n", ans, last.c, s[i].c, s[j].c);
	}
	printf("%lld", ans);
	return 0;
}
