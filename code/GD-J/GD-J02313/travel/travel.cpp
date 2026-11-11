#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		printf ("1");
		char x = s1[2], y = s2[2];
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			printf ("1");
			if ((x >= 'D' && y >= 'D') || (x < 'D' && y < 'D')) {
				printf ("1");
				if (x-y == 1 || x-y == -1) printf ("1");
				else printf ("0");
			}
			else printf ("00");
		}
		else printf ("000");	
	}
	else printf ("0000");
	
	
	return 0;
}
