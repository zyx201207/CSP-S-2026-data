#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	bool b = true;
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0; i < max(c1.size(), c2.size()); i++) {
		if (c1[i] != c2[i]) {
			cout << "0000";
			return 0;
		}
	}
	cout << 1;
	for (int i = 0; i < max(s1.size() - 1, s2.size() - 1); i++) {
		if (s1[i] != s2[i]) {
			cout << 0;
			b = false;
			break;
		}
	}
	char a1, a2;
	if(b){
		cout << 1;		
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] >= 'A' && s1[i] <= 'F') {
				a1 = s1[i];
				a2 = s2[i];
			}
		}
		if (a1 == 'C' && a2 == 'D') {
			cout << "00";
			return 0;
		}
		if (a1 == 'D' && a2 == 'C') {
				cout << "00";
				return 0;
		    }
		if (a1 >= 'A' && a2 >= 'A' && a1 <= 'C' && a2 <= 'C') cout << 1;
		else if (a1 >= 'D' && a2 >= 'D' && a1 <= 'F' && a2 <= 'F') cout << 1;
	} 
	else {
		cout << "00";
		return 0;
	} 
	if (abs(a1 - a2) == 1) cout << 1;
	else cout << 0;
	return 0;
}
