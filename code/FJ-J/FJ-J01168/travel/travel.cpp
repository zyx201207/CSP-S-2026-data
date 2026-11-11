#include<bits/stdc++.h>
using namespace std;

int c[500];
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	c['A']=c['B']=c['C']=1; 
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1!=c2) {
		cout << "0000";
	} else if (s1[0]!=s2[0]||s1[1]!=s2[1]) {
		cout << "1000";
	} else if (c[(int)s1[2]]!=c[(int)s2[2]]) {
		cout << "1100";
	} else if ((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')) {
		cout << "1110";
	} else {
		cout << "1111";
	}
	return 0;
}
