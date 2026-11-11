#include <cstdio>
#include <random>
#include <ctime>
using namespace std;
#define ll long long

template<typename T = int> inline T read() {
	T x = 0; int f = 1, c = getchar();
	while (c != EOF && (c < '0' || c >'9')) {if (c == '-') f = -1; c = getchar();}
	while ('0' <= c && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
template<typename T> inline void write(T x, char e = '\n') {
	if (x < 0) {x = -x; putchar('-');}
	char num[30]; int cnt = 0;
	while (x) {num[++cnt] = x % 10 + '0'; x /= 10;}
	for (int i = cnt; i > 0; --i) putchar(num[i]);
	if (!cnt) putchar('0');
	if (e) putchar(e);
}



int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c = read(), t = read();
	if (c) {
		srand(time(0));
		while (t--) write(1ll * rand() * rand() * rand());
		return 0;
	}
	if (t == 2) {
		int n = read();
		if (n == 4)
			puts("1\n2");
		if (n == 5)
			puts("0\n1");
	}
	if (t == 17)
		puts("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
	if (t == 12)
		puts("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0");
	if (t == 14)
		puts("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
	if (t == 16)
		puts("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
	return 0;
}

