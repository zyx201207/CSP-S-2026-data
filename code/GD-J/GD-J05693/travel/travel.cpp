#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long

using namespace std;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	char se1 = s1[2], se2 = s2[2];
	if(c1 != c2) cout << "0000";
	else {
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			bool b1 = (se1 <= 'C');
			bool b2 = (se2 <= 'C');
			if(b1 && b2) {
				cout << "1";
				bool pan = 0;
				if(se1 == 'A') if(se2 == 'B') pan = 1;
				if(se1 == 'B') if(se2 == 'A' || se2 == 'C') pan = 1;
				if(se1 == 'C') if(se2 == 'B') pan = 1;
				if(se1 == 'D') if(se2 == 'F') pan = 1;
				if(se1 == 'F') if(se2 == 'D') pan = 1;
				if(pan) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		} 
		else cout << "000";
	}
	return 0;
}

