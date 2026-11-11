#include <bits/stdc++.h>
using namespace std;
bool func1(char a, char b) {
	return (a <= 'C' && b <= 'C') || (a >= 'D' && b >= 'D');
} 

bool func2(char a, char b) {
	if (a <= 'C' && b <= 'C') {
		return (abs(a - b) == 1);
	} else if (a >= 'D' && b >= 'D') {
		return true;
	} else {
		return false;
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ss1I = stoi(s1.substr(0, 2));
	int ss2I = stoi(s2.substr(0, 2));
	char ss1C = s1[2];
	char ss2C = s2[2];
	int f1 = 0, f2 = 0, f3 = 0, f4 = 0; 
	f1 = (c1 == c2);
	f2 = (f1 && (ss1I == ss2I));
	f3 = (f2 && func1(ss1C, ss2C));
	f4 = (f2 && func2(ss1C, ss2C));
	cout << f1 << f2 << f3 << f4 << endl;
	return 0;
}
