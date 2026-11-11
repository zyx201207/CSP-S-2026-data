#include <cstdio>
#include <cmath>

typedef long long ll;

ll side(char ch) {
	if (ch == 'A' || ch == 'B' || ch == 'C') return 0;
	return 1;
}

ll pos(char ch) {
	if (ch == 'A') return 0;
	if (ch == 'B') return 1;
	if (ch == 'C') return 2;
	if (ch == 'D') return 4;
	return 5;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ll c1, c2, s1a, s2a;
	char s1b, s2b;
	scanf("%lld%lld%c%lld%lld%c", &c1, &s1a, &s1b, &c2, &s2a, &s2b);
	if (c1 != c2) puts("0000");
	else {
		putchar('1');
		if (s1a!=s2a) puts("000");
		else {
			putchar('1');
			if (side(s1b) != side(s2b)) puts("00");
			else {
				putchar('1');
				putchar((abs(pos(s1b)-pos(s2b))==1)?'1':'0');
			}
		}
	}
	return 0;
}
