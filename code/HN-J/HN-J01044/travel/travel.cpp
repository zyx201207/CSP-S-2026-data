#include <iostream>
#define AC return
#define T1 0
#undef _
using namespace std;

// travel.cpp

// the zip password is Trick||Treat!
// this who can BengZhu (Today is the Hellowhen (i know i spell wrong))
// Too easy
// A water problem
// Just much of XiJie
// 100pts plz

const int N = 1e5 + 3;

int n;

inline int read() {
	return (getchar() - '0') * 10 + (getchar() - '0');
}

inline int abs(int _) {
	return _ < 0 ? -_ : _;
}

int main() {
	ios::sync_with_stdio(false);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	// Too easy
	int a1, a2, b1, b2;
	char c1, c2;
	a1 = read(); getchar(); b1 = read(); c1 = getchar();
	getchar();	// you may think wtf but i can tell you idk
	a2 = read(); getchar(); b2 = read(); c2 = getchar();
	
	if (a1 != a2) {
		printf("0000");
	} else { // you may think wtf too but i can tell you idk again
		putchar('1');
		if (b1 != b2) {
			printf("00");
			if (abs(b1 - b2) == 1 && c1 == c2) putchar('1');
			else putchar('0');
		} else {
			putchar('1');
			if (((c1 > 'C') != (c2 > 'C'))) {
				printf("00");
			} else {
				putchar('1');
				if (c1 > 'C') putchar('0' + (c1 + c2 == 'D' + 'F'));
				else putchar('0' + (abs(c1 - c2) <= 1));
			}
		}
	}
	putchar('\n');
	
	AC T1;
} 
