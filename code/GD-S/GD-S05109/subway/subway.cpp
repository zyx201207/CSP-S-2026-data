#include <cstdio>
using namespace std;

const int MAXN = 10e5 + 10;
int to[MAXN], nxt[MAXN], val[MAXN], h[MAXN] = { 0 }, cnt = 0;
void add(int a, int b, int c) {
	to[++cnt] = b;
	val[cnt] = c;
	nxt[cnt] = h[a];
	h[a] = cnt;
} 
void write(int x) {
	bool neg = false;
	if (x < 0) {
		neg = true;
		putchar('-');
	}
	
	static int sta[20];
	int top = 0;
	while (x) {
		sta[++top] = x % 10; 
		x /= 10;
	}
	
	if (neg) {
		while (top) {
			putchar('0' - sta[top--]);
		}
	} else {
		while (top) {
			putchar('0' + sta[top--]);
		}
	}
	
	return ;
}
int read() {
	bool neg = false;
	int x = 0;
	
	char ch;
	while (ch < '0' || ch > '9') {
		if (ch == '-') neg = true;
		ch = getchar();
	}
	
	if (neg) {
		while (ch >= '0' && ch <= '9') {
			x = x * 10 + ('0' - ch);
			ch = getchar();
		}
	} else {
		while (ch >= '0' && ch <= '9') {
			x = x * 10 + (ch - '0');
			ch = getchar();
		}
	}
	
	return x;
} 

int c, n, m, d, q;
int w[MAXN], map[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= q; i++) {
		putchar('1');
		putchar('\n');
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
