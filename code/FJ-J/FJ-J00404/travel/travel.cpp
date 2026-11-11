#include<bits/stdc++.h>
using namespace std;

int tc(const string& s1,const string& s2) {
	if(s1[1]!=s2[1]) return 0;
	switch(s1[2]) {
		case 'A':
		case 'B':
		case 'C':
			return s2[2]=='A' || s2[2]=='B' || s2[2]=='C' ? 1 : 0;
		case 'D':
			return s2[2]=='F' ? 1 : 0;
		case 'F':
			return s2[2]=='D' ? 1 : 0;
	}
	return 0;
}

int xl(const string& s1,const string& s2) {
	if(s1[1]!=s2[1]) return 0;
	switch(s1[2]) {
		case 'A':
			return s2[2]=='B' ? 1 : 0;
		case 'B':
			return s2[2]=='A' || s2[2]=='C' ? 1 : 0;
		case 'C':
			return s2[2]=='B' ? 1 : 0;
		case 'D':
			return s2[2]=='F' ? 1 : 0;
		case 'F':
			return s2[2]=='D' ? 1 : 0;
	}
	return 0;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1[0]==c2[0] && c1[1]==c2[1] ? 1 : 0) << (s1[1]==s2[1] ? 1 : 0) << tc(s1,s2) << xl(s1,s2);
	return 0;
} 
