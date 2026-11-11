#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
	if(c1 == c2) {
		f1 = 1;
		bool flag = 0;
		for(int i = 0; i < s1.size() - 1; i++) {
			if(s1[i] != s2[i]) {
				flag = 1;
				break;
			}
		}
		if(!flag) {
			f2 = 1;
			char x = s1[2], y = s2[2];
			if((x == 'A' && y == 'B') || (x == 'A' && y == 'C') || (x == 'B' && y == 'A') || (x == 'B' && y == 'C') || (x == 'C' && y == 'A') || (x == 'C' && y == 'B') || (x == 'D' && y == 'F') || (x == 'F' && y == 'D')) {
				f3 = 1; 
				if((x == 'A' && y == 'B') || (x == 'B') && (y == 'A') || (x == 'B' && y == 'C') || (x == 'C') && (y == 'B') || (x == 'D' && y == 'F') || (x == 'F' && y == 'D')) {
					f4 = 1;
				}
			} 
		}
	}
	cout << f1 << f2 << f3 << f4;
	
	return 0;
} 
