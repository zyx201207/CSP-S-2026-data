#include<bits/stdc++.h>
using namespace std;

int c1, s1, c2, s2;
char a, b;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d%c%d%d%c", &c1, &s1, &a, &c2, &s2, &b);
	int x = a - 'A' + 1, y = b - 'A' + 1;
	if (c1 == c2)	
		printf("1");
	else
		printf("0");
	if (c1 == c2 && s1 == s2)
		printf("1");
	else
		printf("0");
	if (c1 == c2 && s1 == s2 && ((x >= 1 && x <= 3 && y >= 1 && y <= 3) || (x >= 4 && x <= 5 && y >= 4 && y <= 5)))
		printf("1");
	else
		printf("0");
	if (c1 == c2 && s1 == s2 && (x - y == 1 || y - x == 1))
		if ((x == 3 && y == 4) || (x == 4 && y == 3))
			printf("0");
		else
			printf("1");
	else
		printf("0\n");
	return 0;
}





