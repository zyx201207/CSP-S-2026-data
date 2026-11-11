#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
string p1, p2;
signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >>c1>>s1>>c2>>s2;
    if (c1==c2) cout<<'1';
    else {
    	cout << "0000\n";
    	return 0;
	}
    p1=string()+s1[0]+s1[1];
    p2=string()+s2[0]+s2[1];
    if (p1==p2) cout <<'1';
    else {
    	cout << "000\n";
    	return 0;
	}
    if (s1[2]=='D'&&s2[2]=='F'||
	    s1[2]=='F'&&s2[2]=='D'||
		s1[2]=='A'&&s2[2]=='B'||
		s1[2]=='B'&&s2[2]=='A'||
		s1[2]=='B'&&s2[2]=='C'||
		s1[2]=='C'&&s2[2]=='B') cout <<"11\n";
	else {
		if (s1[2]=='A'&&s2[2]=='C'||
		    s1[2]=='C'&&s2[2]=='A') cout << "10\n";
		else cout << "00\n";
	}
}
