#include <bits/stdc++.h>
using namespace std;
char c1[10], s1[10], c2[10], s2[10];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int l1, l2, l3, l4;
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0; i < 2; i++) {
		if (c1[i] != c2[i]) {
			cout << "0000" << "\n";
			return 0;
		}
	}
	if (s1[1] != s2[1]) {
		cout << "1000" << "\n";
		return 0;
	}
	bool flag = false;
	if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))
		flag = true;
	if (!flag) {
		cout << "1100" << "\n";
		return 0;
	}	
	int p = int(s1[2]), q = int(s2[2]);
	if (abs(p - q) == 1) {
		cout << "1111" << "\n";
	} else {
		cout << "1110" << "\n";
	}
	return 0;
} 
