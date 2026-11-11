#include <ctype.h>
#include <stdio.h>
#define FileIO(str) freopen(str".in", "r", stdin); freopen(str".out", "w", stdout);
void read(int *x) {
	int f = 1, tmp = 0;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -f;
		}
		ch = getchar();
	}
	do {
		tmp = (tmp << 1) + (tmp << 3) + (ch ^ 48);
		ch = getchar();
	} while(isdigit(ch));
	*x = tmp * f;
}
int c1, c2, s1, s2;
char ss1[2], ss2[2]; 
int main() {
	FileIO("travel");
	scanf("%d%d%s%d%d%s", &c1, &s1, ss1, &c2, &s2, ss2);
	if (c1 == c2) {
		putchar(49);
		if (s1 == s2) {
			putchar(49);
			if (ss1[0] <= 'C' && ss2[0] <= 'C') {
				putchar(49);
				if (ss1[0] > ss2[0]) {
					char tmp = ss1[0];
					ss1[0] = ss2[0];
					ss2[0] = tmp;
				}
				if (ss1[0] == 'A' && ss2[0] == 'B' || ss1[0] == 'B' && ss2[0] == 'C') {
					putchar(49);
				}
				else {
					putchar(48);
				}
			}
			else if(ss1[0] >= 'D' && ss2[0] >= 'D') {
				puts("11");
			}
			else {
				puts("00");
			}
		}
		else {
			puts("000");
		}
	}
	else {
		puts("0000");
	}
}
