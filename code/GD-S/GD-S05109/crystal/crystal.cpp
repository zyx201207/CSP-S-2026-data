#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 5e5 + 10;
const int MAXN2 = MAXN/2;
typedef long long ull;

int a[MAXN], s[MAXN] = { 0 };
int n;
ull m;

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
ull ullr() {
	bool neg = false;
	ull x = 0;
	
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
/*void qsort(int l, int r, int arr[]) {
	if (l == r) return ;
	int mid = l - (r - 1) / 2;
	
	int c1 = 0, c2 = 0;
	for (int i = l; i <= r; i++) {
		if (arr[i] < arr[mid]) f[++c1] = i;
		else if (arr[i] > arr[mid]) b[++c2] = i;
	}
	
	qsort(1, c1, f);
	qsort(1, c2, b);
} */

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(), m = ullr();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	
	bool flag = true;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		s[i] = a[i] - a[i - 1];
		if (i >= 3 && flag) {
			if (s[i] != s[i - 1]) flag = false;
		}
	}
	
	if (flag) {
		ull cnt = 0;
		for (int i = n; i >= 1; i--) {
			cnt += a[i];
			if (cnt > m) {
				write(n - i);
				return 0;
			}
		}
		write(n);
		return 0;
	}
	
	/*
	for (int i = 1; i <= n; i++) {
		write(a[i]);
		putchar(' ');
	}
	putchar('\n');
	for (int i = 1; i <= n; i++) {
		write(s[i]);
		putchar(' ');
	}
	putchar('\n');*/
	
	int ans = 0, num = 0;
	for (int i = 1; i <= n; i++) {
		ull cnt = 0;
		int j, ca = m;
		
		for (j = i + 1; j <= n; j++) {
			num++;
			if (num >= 13e8) {
				putchar('1');
				return 0;
			}
			
			ull tmp = m + s[j] + cnt;
			//printf("i:%d j:%d tmp:%d cnt:%d a[i]:%d s[j]:%d\n", i, j, tmp, cnt, a[i], s[j]);
			if (tmp >= 0) {
				m = tmp, cnt += s[j];
			} else {
				j--;
				break;
			}
		}
		
		m = ca;
		ans = max(ans, j - i);
	}
	
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
