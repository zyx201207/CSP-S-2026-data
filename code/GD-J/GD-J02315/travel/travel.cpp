#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

char c1[10], s1[10], c2[10], s2[10];
int a[500], b[500];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	a[(int)'A'] = a[(int)'B'] = a[(int)'C'] = 1;
	a[(int)'D'] = a[(int)'F'] = 2;
	b[(int)'A'] = 1;
	b[(int)'B'] = 2;
	b[(int)'C'] = 3;
	b[(int)'D'] = 4;
	b[(int)'F'] = 5;
	scanf("%s%s%s%s", c1, s1, c2, s2);
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		printf("1");
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			printf("1");
			if (a[(int)s1[2]] == a[(int)s2[2]]) {
				printf("1");
				if (abs(b[(int)s1[2]] - b[(int)s2[2]]) == 1)
					printf("1");
				else
					printf("0");
			} else
				printf("00");
		} else
			printf("000");
	} else
		printf("0000");
	return 0;
}
