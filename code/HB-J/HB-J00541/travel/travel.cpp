#include<bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for(int i = (a); i <= (b); i++)
#define ro(i, a, b) for(int i = (a); i >= (b); i--)
//#define int long long 


string c1, s1, c2, s2;




bool ck() {
	if(s1[2] == 'D' || s1[2] == 'F') {
		if(s2[2] == 'D' || s2[2] == 'F') return 1;
		else return 0;
	}
	else {
		if(s2[2] == 'D' || s2[2] == 'F') return 0;
		else return 1;
	}
	
}
bool ck2() {
	if(s1[2] == 'D' || s1[2] == 'F') {
		if(s1[2] == s2[2]) return 0;
		else return 1;
	}
	else {
		if(s1[2] == 'A' && s2[2] == 'C') return 0;
		if(s1[2] == 'C' && s2[2] == 'A') return 0;
		return 1;
	}
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	
	if(s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	
	if(ck()) cout << 1;
	else {
		cout << "00";
		return 0;
	}
	
	if(ck2()) cout << 1;
	else cout << 0;
	
	return 0;
}
/*

*/
