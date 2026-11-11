#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) printf("0000");
	else {
		printf("1");
		string a1 = s1.substr(0, 2), a2 = s2.substr(0, 2);
		if (a1 != a2) printf("000");
		else {
			printf("1");
			char ch1 = s1[2], ch2 = s2[2];
			if ((ch1 <= 'C' && ch2 <= 'C') || (ch1 > 'C' && ch2 > 'C')) {
				printf("1%d", abs(ch1 - ch2) == 1);
			} else printf("00");
		}
	}
	return 0;
}
