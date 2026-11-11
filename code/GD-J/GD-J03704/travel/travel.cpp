#include <bits/stdc++.h>
using namespace std;

bool a, b, c, d;
char c12, c22;
int s1, c11, s2, c21;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%02d %02d%c %02d %02d%c", &s1, &c11, &c12, &s2, &c21, &c22);
	if (s1 == s2) {
		a = 1;
		if (c11 == c21) {
			b = 1;
			if ((((c12 <= 67) && (c22 <= 67)) || ((c12 > 67) && (c22 > 67))) && abs(c12 - c22) <= 2) {
				c = 1;
				if (abs(c12 - c22) == 1)
					d = 1;
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}
