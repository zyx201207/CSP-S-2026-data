#include <stdio.h>

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, s1, c2, s2;
	char ss1, ss2;
	scanf("%02d %02d%c %02d %02d%c", &c1, &s1, &ss1, &c2, &s2, &ss2);
	printf("%d%d%d%d", c1 == c2 ? 1 : 0, c1 == c2 && s1 == s2 ? 1 : 0, c1 == c2 && s1 == s2 && (ss1 < 'D') == (ss2 < 'D') ? 1 : 0, c1 == c2 && s1 == s2 && (ss1 < 'D') == (ss2 < 'D') && (ss1-ss2 == 1 || ss2-ss1 == 1) ? 1 : 0);
	return 0;
}

