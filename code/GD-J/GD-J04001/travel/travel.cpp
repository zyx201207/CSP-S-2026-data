#include <stdio.h>
#include <string.h> 
char c1[100], c2[100], c3[100], c4[100];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s %s %s %s", c1, c2, c3, c4);
	bool r1 = strcmp(c1, c3) == 0;
	if (r1) {
		printf("1");
	} else printf("0");
	bool r2 = (c2[0] == c4[0]) && (c2[1] == c4[1]) && r1;
	if (r2) {
		printf("1");
	} else printf("0");
	bool r3 = 0;
	if (r2) {
		int l = (c2[2] == 'D') || (c2[2] == 'F');
		int r = (c4[2] == 'D') || (c4[2] == 'F');
		if (l == r) {
			printf("1");
			r3 = 1;
		} else printf("0");
	} else printf("0");
	if (r3) {
		if (c2[2] - c4[2] == 1 || c4[2] - c2[2] == 1) {
			printf("1");
		} else printf("0");
	} else printf("0");
	return 0;
} 
