#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
string answer = "0000";
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		answer[0] = '1';
		if(s1[0] == s2[0] && s1[1] == s2[1]) {
			answer[1] = '1';
			if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')) answer[2] = '1';
		}
		
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]) {
		if((s1[2] - 1) == s2[2] || (s2[2] - 1) == s1[2]) {
			if(s1[2] != 'D' && s2[2] != 'D') answer[3] = '1';
			else {
				if(s1[2] == 'F' || s2[2] == 'F') answer[3] = '1';
			}
		}
	}
	cout << answer;
	return 0;
}