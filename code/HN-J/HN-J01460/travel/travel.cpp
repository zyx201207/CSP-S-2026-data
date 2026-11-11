/*
期望得分：100pts 
*/ 
#include <bits/stdc++.h>

using namespace std;
#define ll long long

char a[5], b[5], c[5], d[5];

bool calc1() {
	return a[1] == c[1] && a[2] == c[2];
}

bool calc2() {
	return calc1() && (b[1] == d[1] && b[2] == d[2]);
}

bool calc3() {
	return calc2() && ((b[3] <= 'C' && d[3] <= 'C') || (b[3] >= 'D' && d[3] >= 'D'));
}

bool calc4() {
	return (b[1] == d[1] && b[2] == d[2]) && ((b[3] <= 'C' && d[3] <= 'C') || (b[3] >= 'D' && d[3] >= 'D')) && ((abs(b[3] - d[3]) == 1) || (b[3] >= 'D' && d[3] >= 'D'));
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", a + 1, b + 1, c + 1, d + 1);
	if (calc1()) putchar('1');
	else putchar('0');
	if (calc2()) putchar('1');
	else putchar('0');
	if (calc3()) putchar('1');
	else putchar('0');
	if (calc4()) putchar('1');
	else putchar('0'); 
	return 0;
}

