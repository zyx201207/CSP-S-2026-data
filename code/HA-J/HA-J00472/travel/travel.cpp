#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
bool b1, b2, b3, b4;

bool tygd() {
	return (s1[2] <= 'C') == (s2[2] <= 'C');
}
bool xl() {
	if(!tygd()) return 0;
	if(s1[2] <= 'C' && s2[2] <= 'C') {
		int a = s1[2] - s2[2];
		if(a < 0) {
			a = -a;
		}
		return a == 1;
	} else {
		int a = s1[2] - s2[2];
		if(a < 0) {
			a = -a;
		}
		return a == 2;
	}
	return 0;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1 == c2)<<(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])<<(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && tygd())<<(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && tygd() && xl());
	
	return 0;
}
