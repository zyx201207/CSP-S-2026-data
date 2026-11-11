#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2) return cout << "0000", 0;
	if(10*(s1[0]-'0')+s1[1]-'0'!=10*(s2[0]-'0')+s2[1]-'0')
		return cout << "1000", 0;
	if(s1[2]=='D') {
		if(s2[2]=='F') cout << "1111";
		else cout << "1100";
	} else if(s1[2]=='F') {
		if(s2[2]=='D') cout << "1111";
		else cout << "1100";
	} else {
		if(s2[2]=='D'||s2[2]=='F') return cout << "1100", 0;
		else {
			if(s1[2]=='A'&&s2[2]=='B') return cout << "1111", 0;
			if(s1[2]=='B'&&s2[2]=='A') return cout << "1111", 0;
			if(s1[2]=='B'&&s2[2]=='C') return cout << "1111", 0;
			if(s1[2]=='C'&&s2[2]=='B') return cout << "1111", 0;
			cout << "1110";
		}
	}
	return 0;
}
