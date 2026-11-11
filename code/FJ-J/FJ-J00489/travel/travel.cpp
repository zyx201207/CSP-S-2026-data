#include <bits/stdc++.h>
using namespace std;
int a, b;
char x[100], y[100];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %s%d %s", &a, x, &b, y);
	if (a == b) {
		putchar('1');
		if (x[0] == y[0] && x[1] == y[1]) {
			putchar('1');
			if (!((x[2] <= 'C' && y[2] >= 'D') || (x[2] >= 'D' && y[2] <= 'C'))) {
				putchar('1');
				if (abs((int)x[2] - y[2]) == 1) {
					putchar('1');
				}
				else {
					putchar('0');
				}
			}
			else {
				putchar('0');
				putchar('0');
			}
		}
		else {
			putchar('0');
			putchar('0');
			putchar('0');
		}
	}
	else {
		putchar('0');
		putchar('0');
		putchar('0');
		putchar('0');
	}
	return 0;
}
