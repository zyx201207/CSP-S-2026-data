#include <bits/stdc++.h>
using namespace std;
char a1[6], a2[6];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n1 = 0, n2 = 0;
	cin >> n1;
	cin >> a1;
	cin >> n2;
	cin >> a2;
	int p1 = (a1[0] - '0') * 10 + (a1[1] - '0'), w1 = 0, p2 = (a2[0] - '0') * 10 + (a2[1] - '0'), w2 = 0;
	if (a1[2] == 'A') w1 = 1;
	else if (a1[2] == 'B') w1 = 2;
	else if (a1[2] == 'C') w1 = 3;
	else if (a1[2] == 'D') w1 = 4;
	else w1 = 5;
	if (a2[2] == 'A') w2 = 1;
	else if (a2[2] == 'B') w2 = 2;
	else if (a2[2] == 'C') w2 = 3;
	else if (a2[2] == 'D') w2 = 4;
	else w2 = 5;
	if (n1 == n2) {
		cout << 1;
		if (p1 == p2) {
			cout << 1;
			if (w1 <= 3 && w2 <= 3 || w1 >= 4 && w2 >= 4) {
				cout << 1;
				if (w1 - 1 == w2 || w1 + 1 == w2) {
					cout << 1;
				} else{
					cout << 0;
				}
			} else {
				cout << 0 << 0; 
			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}
