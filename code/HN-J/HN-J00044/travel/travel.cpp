#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int strtoi(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		res = res*10 + (s[i] - '0');
	}
	return res;
}

int check(char idx1, char idx2) {
	if (idx1 == 'A' && idx2 == 'B') return 2;
	if (idx1 == 'A' && idx2 == 'C') return 1;
	if (idx1 == 'B' && idx2 == 'C') return 2;
	if (idx2 == 'A' && idx1 == 'B') return 2;
	if (idx2 == 'A' && idx1 == 'C') return 1;
	if (idx2 == 'B' && idx1 == 'C') return 2;
	
	if (idx1 == 'D' && idx2 == 'E') return 2;
	if (idx2 == 'D' && idx1 == 'E') return 2;
	
	return 0;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string _tmps1, _tmps2;
	cin >> c1 >> _tmps1 >> c2 >> _tmps2;
	 
	int line1 = strtoi(_tmps1.substr(0, 2));
	char idx1 = _tmps1.back();
	int line2 = strtoi(_tmps2.substr(0, 2));
	char idx2 = _tmps2.back();
	
	if (c1 == c2) {
		cout << 1;
		if (line1 == line2) {
			cout << 1;
			if (check(idx1, idx2) >= 1) {
				cout << 1;
				if (check(idx1, idx2) == 2) cout << 1;
				else cout << 0;
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}
