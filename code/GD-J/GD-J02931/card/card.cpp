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
void write(int x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + 48);
}
int nxt[500001], n, m, a[500001], cnt[300001], ccnt[300001];
int main() {
	FileIO("card");
	read(&n);
	read(&m);
	for (int i = 1; i <= n; ++i) {
		read(&a[i]);
		++ccnt[a[i]];
	}
	for (int i = 1; i <= n; ++i) {
		nxt[a[i]] = a[i + 1];
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = i; j; j = nxt[j]) {
			cnt[j] += ccnt[i];
		}
	}
	for (int i = 1; i <= m; ++i) {
		write(cnt[i]);
		i != m ? putchar(32) : 0;
	}
}
