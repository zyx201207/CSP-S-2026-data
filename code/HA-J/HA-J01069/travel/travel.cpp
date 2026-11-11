#include<bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
bool f1, f2, f3, f4;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0] == c2[0] && c1[1] == c2[1]) {
		f1 = 1;
	} else {
		f1 = 0;
	}
	
	if(f1 && s1[0] == s2[0] && s1[1] == s2[1]) {
		f2 = 1;
	} else {
		f2 = 0;
	}
	
	if(f2 && (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')) {
		if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
			f3 = 1;
		}
		else {
			f3 = 0;
			
		}

	} else {
		if(f2 && (s1[2] == 'D' || s1[2] == 'F')) {
			if(s2[2] == 'D' || s2[2] == 'F') {
				f3 = 1;
			}
			else {
				f3 = 0;
			}
		} else {
			f3 = 0;
		}
	}
	
	
	if(f3) {
		if(s2[2] == s1[2]+1 || s2[2] == s1[2]-1) {
			f4 = 1;
		}
		else {
			f4 = 0;
		}
	} else {
		f4 = 0;
	}
	cout << f1 << f2 << f3 << f4;
	return 0;
}



















