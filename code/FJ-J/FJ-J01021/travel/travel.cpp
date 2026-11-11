#include <cstdio>
int c1, c2;
char s1[3], s2[3];
int abs(int n) {return n < 0 ? -n : n;}
bool check1() {
	if (s1[0] == s2[0] && s1[1] == s2[1]) return 1;
	return 0;
}
bool check2() {
	if (s1[2] >= 'A' && s1[2] <= 'C') {
		if (s2[2] >= 'A' && s2[2] <= 'C') return 1;
	} else {
		if (s2[2] >= 'D' && s2[2] <= 'F') return 1;
	}
	return 0;
}
bool check3() {
	if (abs(s1[2] - s2[2]) == 1 || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) return 1;
	return 0;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d\n%s%d\n%s", &c1, s1, &c2, s2);
	if (c1 == c2) {
		if (check1()) {
			if (check2()) {
				if (check3()) {
					printf("1111");
				} else printf("1110"); 
			} else printf("1100");
		} else printf("1000");
	} else printf("0000");
	return 0;
}
