#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2, s = "0ABCDF";
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	
	int a = s1[0]*10 + s1[1], 
		b = s2[0]*10 + s2[1];
	if(a == b) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C') {
		if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C') {
			cout << "1";
		} else {
			cout << "00";
			return 0;
		}
	} if(s1[2]=='D' || s1[2]=='F') {
		if(s2[2]=='D' || s2[2]=='F') {
			cout << "1";
		} else {
			cout << "00";
			return 0;
		}
	}
	
	if((s[s.find(s1[2])+1] == s2[2]) || (s[s.find(s1[2])-1] == s2[2])) {
		cout << "1";
	} else {
		cout << "0";
	}
	
	return 0;
}
