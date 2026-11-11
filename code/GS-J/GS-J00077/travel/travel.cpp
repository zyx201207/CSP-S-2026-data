#include <bits/stdc++.h>
using namespace std;

int JHabs(int i) {
	if (i >= 0) return i;
	else return 0 - i;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	int _1, _2, _3, _4;
	
	if (c1 == c2) {
		_1 = 1;
	}
	else {
		_1 = 0;
		_2 = 0;
		_3 = 0;
		_4 = 0;
		cout << _1 << _2 << _3 << _4 << endl;
		return 0;
	}
	
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		if (s1[2] != s2[2]) {
			_2 = 1;
		}
		else {
			_2 = 0;
			_3 = 0;
			_4 = 0;
			cout << _1 << _2 << _3 << _4 << endl;
			return 0;
		}
	}
	else {
		_2 = 0;
		_3 = 0;
		_4 = 0;
		cout << _1 << _2 << _3 << _4 << endl;
		return 0;
	}
	
	if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') {
		_3 = 1;
	}
	else if (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F') {
		_3 = 1;
	}
	else {
		_3 = 0;
		_4 = 0;
		cout << _1 << _2 << _3 << _4 << endl;
		return 0;
	}
	
	int s12 = s1[2], s22 = s2[2];
	if (JHabs(s12 - s22) == 1) {
		if (s1[2] != 'C' && s1[2] != 'D') {
			_4 = 1;
		}
        else {
        	_4 = 0;
		}
	}
	else if (s1[2] == 'D' && s1[2] == 'F') {
		_4 = 1;
	}
	else {
		_4 = 0;
	}
	
	cout << _1 << _2 << _3 << _4 << endl;
	return 0;
}
