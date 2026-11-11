#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin); freopen("travel.out", "w", stdout);
	int c1, s1, c2, s2;
	char ss1, ss2;
	scanf("%d %d%c %d %d%c", &c1, &s1, &ss1, &c2, &s2, &ss2);
	if (c1 != c2) {
		printf("0000");
		return 0;
	}
	if (s1 != s2) {
		printf("1000");
		return 0;
	}
	if (ss1 > ss2) swap(ss1, ss2);
	bool ab = (ss1 == 'A' && ss2 == 'B');
	bool ac = (ss1 == 'A' && ss2 == 'C');
	bool bc = (ss1 == 'B' && ss2 == 'C');
	bool df = (ss1 == 'D' && ss2 == 'F');
	printf("11%d%d", ab||ac||bc||df, ab||bc||df);
	return 0;
}
