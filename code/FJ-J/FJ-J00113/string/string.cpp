#include <cstdio>

typedef long long ll;

ll s[200005];
char c[200005];

ll s1[200005];
char c1[200005];

ll s2[200005];
char c2[200005];

ll n;

void split() {
	ll totl = s[n];
	
	for (ll p = 0; p <= n ; p ++) {
		s1[p] = s[p];
		c1[p] = c[p];
		s2[n-p] = totl - s[p];
		c2[n-p-1] = c[p];
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1 ; i <= n ; i ++) {
		ll a;
		scanf("%lld %c", &a, &c[i-1]);
		s[i] = s[i-1] + a;
	}
	split();
	ll lptr = 0, rptr = 0, pos = 0, cnt = 0;
	while (lptr < n || rptr < n) {
//		printf("[D] %lld %lld %lld %lld %c %c", cnt, pos, lptr, rptr, c1[lptr], c2[rptr]);
		if (s1[lptr+1] > s2[rptr + 1]) {
			if (c1[lptr] != c2[rptr]) cnt += s2[rptr+1]-pos;
			pos = s2[rptr+1];
			rptr ++;
//			puts(" R+");
		} else if (s1[lptr+1] < s2[rptr + 1]) {
			if (c1[lptr] != c2[rptr]) cnt += s1[lptr+1]-pos;
			pos = s1[lptr+1];
			lptr ++;
//			puts(" L+");
		} else {
			if (c1[lptr] != c2[rptr]) cnt += s1[lptr+1]-pos;
			pos = s1[lptr+1];
			lptr++; rptr++;
//			puts(" ++");
		}
	}
	printf("%lld", cnt/2);
	return 0;
}
