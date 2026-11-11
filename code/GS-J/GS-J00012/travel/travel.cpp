#include<bits/stdc++.h>
using namespace std;

int x, y, u, v, a, b;
char c1[12], s1[12], c2[12], s2[12];

int main() {
	//Trick||Treat!
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
	x = (c1[1] - '0') * 10 + (c1[2] - '0');
	y = (c2[1] - '0') * 10 + (c2[2] - '0');
	u = s1[3] - 'A';
	v = s2[3] - 'A';
	a = (s1[1] - '0') * 10 + (s1[2] - '0');
	b = (s2[1] - '0') * 10 + (s2[2] - '0');
	if (x == y) printf("1");
	else printf	("0");
	if (x == y && a == b) printf("1");
	else printf	("0");
	if (x == y && a == b && ((u == 0 && (v == 1 || v == 2)) || 
		(u == 1 && (v == 0 || v == 2)) || (u == 2 && (v == 0 || v == 1)) || 
		(u == 3 && v == 4) || (u == 4 && v == 3))) printf("1");
	else printf	("0");
	if (x == y && a == b && ((u == 0 && v == 1) || 
		(u == 1 && (v == 0 || v == 2)) || (u == 2 && v == 1) || 
		(u == 3 && v == 4) || (u == 4 && v == 3))) printf("1");
	else printf	("0");	
}
