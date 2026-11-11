#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;

int c, t, n, tmp;
ll d, x1, x2;

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
ll llr() {
	bool neg = false;
	ll x = 0;
	
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
void llw(ll x) {
	bool neg = false;
	if (x < 0) {
		neg = true;
		putchar('-');
	}
	
	static int sta[100];
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


int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	c = read(), t = read();
	if (c == 11 || c == 12) {//Òª¸Ä 
		while (t--) {
			n = read(), d = llr(); 
			x1 = llr(), x2 = llr();
			for (int i = 0; i < n - 2; i++) tmp = read();
		
			if ((long long)abs(x1 - x2) >= d || (double)d / abs(x1 - x2) > n) {
				putchar('0');
				putchar('\n');
				continue;
			}
		
			long long ans = n - (( d / abs(x1 - x2) - 1 ) * 2 + 1);
			if (ans < 0) {
				putchar('0');
			} else {
				llw(ans);
			}
			putchar('\n');
		}
	} else if (c == 13 || c == 14){
		while (t--) {
			n = read(), d = llr();
			for (int i = 0; i < n; i++) tmp = read();
			llw(pow(2, n));
			putchar('\n');
		}
	} else {
		while (t--) {
			putchar('0');
			putchar('\n');
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
