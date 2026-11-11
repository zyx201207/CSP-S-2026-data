#include <ctype.h>
#include <stdio.h>
#define FileIO(str) freopen(str".in", "r", stdin); freopen(str".out", "w", stdout);
void read(int *x) {
	int f = 1, tmp = 0;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -f;
		}
		ch = getchar();
	}
	do {
		tmp = (tmp << 1) + (tmp << 3) + (ch ^ 48);
		ch = getchar();
	} while(isdigit(ch));
	*x = tmp * f;
}
void write(long long x) {
	if (x < 0ll) {
		x = -x;
		putchar('-');
	}
	if (x > 9ll) {
		write(x / 10ll);
	}
	putchar(x % 10ll + 48ll);
}
int min(int x, int y) {
	return x < y ? x : y;
}
int n, a[200001], l, r, div;
char s[200001][2];
long long cnt;
int main() {
	FileIO("string");
	read(&n);
	l = 1;
	r = n;
	for (int i = 1; i <= n; ++i) {
		read(&a[i]);
		scanf("%s", s[i]);
	}
	while (l < r) {
		div = min(a[l], a[r]);
		a[l] -= div;
		a[r] -= div;
		if (s[l][0] != s[r][0]) {
			cnt += div;
		}
		if (a[l] == 0) {
			++l;
		}
		if (a[r] == 0) {
			--r;
		}
	}
	write(cnt);
}
