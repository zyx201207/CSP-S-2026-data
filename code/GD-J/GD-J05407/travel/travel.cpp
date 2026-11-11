#include<iostream>
#include<string>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) cout << "11\n";
			else if((s1[2] != 'D' && s1[2] != 'F') && (s2[2] != 'D' && s2[2] != 'F')) {
				cout << "1";
				if((int)(s1[2]) - (int)(s2[2]) == 1 || (int)(s2[2]) - (int)(s1[2]) == 1) cout << "1\n";
				else cout << "0\n";
			} else cout << "00\n";
		} else cout << "000\n";
	} else cout << "0000\n";
	return 0;
} 
