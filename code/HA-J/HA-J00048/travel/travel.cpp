#include <cstdio>

int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	
	char	s1[16], s2[8];
	int		c1, c2;
	scanf ("%d%s%d%s", &c1, s1, &c2, s2);
	
	if (c1 == c2) {
		putchar ('1');
		if (s1[0] == s2[0] and s1[1] == s2[1]) {
			putchar ('1');
			char x = s1[2], y = s2[2];
			if (x == 'D' or x == 'F') {
				if (y == 'D' or y == 'F') {
					putchar ('1');
					if (x == 'D' and y == 'F') {
						putchar ('1');
					} else if (x == 'F' and y == 'D') {
						putchar ('1');
					} else {
						putchar ('0');
					}
				} else {
					printf ("00");
				}
			}
			if (x == 'A' or x == 'B' or x == 'C') {
				if (y == 'A' or y == 'B' or y == 'C') {
					putchar ('1');
					if (x == 'A' and y == 'B') {
						putchar ('1');
					} else if (x == 'B' and (y == 'A' or y == 'C')) {
						putchar ('1');
					} else if (x == 'C' and y == 'B') {
						putchar ('1');
					} else {
						putchar ('0');
					}
				} else {
					printf ("00");
				}
			}
		} else {
			printf ("000");
		}
	} else {
		printf ("0000");
	}

	return 0;
}
