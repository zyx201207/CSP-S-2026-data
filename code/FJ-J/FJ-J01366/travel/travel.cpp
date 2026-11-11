#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool book[10];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string line1 = s1.substr(0, 2), line2 = s2.substr(0, 2);
	if (c1 == c2) {
		book[0] = true;
		if (line1 == line2) {
			book[1] = true;
			if (((s1[2] <= 'C') && (s2[2] <= 'C')) || ((s1[2] > 'C') && (s2[2] > 'C'))) {
				book[2] = true;
				if (abs(s1[2]-s2[2]) == 1)
					book[3] = true;
			}
		}
	}
	for (int i = 0; i < 4; i++)
		cout << book[i];
	return 0;
}
