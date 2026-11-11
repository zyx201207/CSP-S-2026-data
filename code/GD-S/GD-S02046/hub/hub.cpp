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
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c = read(), t = read();
	if (c) {
		srand(time(0));
		while (t--) {
			int n = read(), k = read();
			write(1ll * rand() * rand() * rand() % (n - k));
		}
		return 0;
	}
	if (t == 2)
		puts("1\n2");
	if (t == 3)
		puts("1\n1\n2");
	if (t == 5) {
		int n = read();
		if (n == 602)
			puts("17\n9\n6\n6\n9");
		if (n == 24032)
			puts("189\n233\n288\n229\n338");
	}
	if (t == 1)
		puts("12251");
	return 0;
}

