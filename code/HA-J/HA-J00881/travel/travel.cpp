#include <bits/stdc++.h>
using namespace std;
bool check1(string s1,string s2) {
	char a = s1[2],b = s2[2];
	if ((a >= 'A' && a <= 'C') && (b >= 'A' && b <= 'C'))
		return true;
	if ((a >= 'D' && a <= 'F') && (b >= 'D' && b <= 'F'))
		return true;
	return false;
}
bool check2(string s1,string s2) {
	char a = s1[2],b = s2[2];
	if (max((int)a,(int)b) - min((int)a,(int)b) == 1 || ((char)max((int)a,(int)b) == 'F' && (char)min((int)a,(int)b) == 'D')) {
		if ((char)max((int)a,(int)b) == 'D' && (char)min((int)a,(int)b) == 'C') return false;
		return true;
	}
	return false;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) cout << "0000";
	else if (s1[0] != s2[0] || s1[1] != s2[1]) cout << 1000;
	else if (!check1(s1,s2)) cout << 1100;
	else if (!check2(s1,s2)) cout << 1110;
	else cout << 1111;
	return 0;
}
