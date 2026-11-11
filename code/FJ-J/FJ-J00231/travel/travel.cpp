#include <bits/stdc++.h>
using namespace std;

int a, b;
string s1, s2, s3, s4;

int main() {
	freopen("travel4.in", "r", stdin);
	freopen("travel4.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1[0] != s3[0] || s1[1] != s3[1]) cout <<"0000";
	else {
		if(s2[0] == s4[0] && s2[1] == s4[1]) {
			if(s2[2] == 'A') {
				if(s4[2] == 'B') cout << "1111";
				if(s4[2] == 'C') cout << "1110";
				if(s4[2] == 'D' || s4[2] == 'F') cout << "1100";
			}
			if(s2[2] == 'B') {
				if(s4[2] == 'A' || s4[2] == 'C') cout << "1111";
				if(s4[2] == 'D' || s4[2] == 'F') cout << "1100";
			}
			if(s2[2] == 'C') {
				if(s4[2] == 'B') cout << "1111";
				if(s4[2] == 'A') cout << "1110";
				if(s4[2] == 'D' || s4[2] == 'F') cout << "1100";
			}
			if(s2[2] == 'D') {
				if(s4[2] == 'F') cout << "1111";
				if(s4[2] == 'A' || s4[2] == 'B'|| s4[2] == 'C') cout << "1100";
			}
			if(s2[2] == 'F') {
				if(s4[2] == 'D') cout << "1111";
				if(s4[2] == 'A' || s4[2] == 'B'|| s4[2] == 'C') cout << "1100";
			}
		} else cout << "1000";
	}
	return 0;
}
