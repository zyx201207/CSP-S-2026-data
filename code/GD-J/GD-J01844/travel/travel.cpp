#include <bits/stdc++.h>
using namespace std;
int c1, c2, s1, s2;
char ch1, ch2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d%c%d%d%c", &c1, &s1, &ch1, &c2, &s2, &ch2);
	bool flag = true;
	if (c1 == c2 && flag)
		printf("1");
	else
		printf("0"), flag = false;
	if (s1 == s2 && flag)
		printf("1");
	else
		printf("0"), flag = false;
	if (((ch1 <= 'C' && ch2 <= 'C') || (ch1 >= 'E' && ch2 >= 'E')) && flag)
		printf("1");
	else
		printf("0"), flag = false;
	int x = ch1, y = ch2;
	if (abs(x - y) == 1 && flag)
		printf("1");
	else
		printf("0"), flag = false;
	return 0;
}
