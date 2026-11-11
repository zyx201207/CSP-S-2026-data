#include <bits/stdc++.h>

using namespace std;

const int N = 201000;

int a, b, c, d;
char ch1, ch2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> ch1 >> c >> d >> ch2;
	if (a != c) {
		printf("0000");
	} else {
		printf("1");
		printf(b == d ? "1" : "0");
		if (b == d && ((ch1 <= 'C' && ch2 <= 'C') || (ch1 >= 'D' && ch1 <= 'F' && ch2 >= 'D' && ch2 <= 'F'))) printf("1");
		else printf("0");
		if (b == d) {
			if (ch1 + ch2 == 'C' + 'D') printf("0");
			else if (abs(ch1 - ch2) == 1) printf("1");
			else printf("0");
		} else {
			printf("0");
		}
	}
	puts("");
	return 0;
} 
