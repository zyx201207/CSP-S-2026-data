#include <bits/stdc++.h>
using namespace std;

string a1, a2, b1, b2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	if (a1 == b1) {
		printf("1");
		if (a2 [0] == b2 [0] && a2 [1] == b2 [1]) {
			printf("1");
			bool a;
			if (a2 [2] == 'A' || a2 [2] == 'B' || a2 [2] == 'C') a = true;
			else a = false;
			bool b;
			if (b2 [2] == 'A' || b2 [2] == 'B' || b2 [2] == 'c') b = true;
			else b = false;
			if (!(a ^ b)) {
				printf("1");
				if (abs(a2 [2] - b2 [2]) == 1) printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
