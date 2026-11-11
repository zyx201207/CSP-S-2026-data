#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2) cout << 1;
	else cout << 0;
	
	int a1=s1[0]-'0',a2=s2[0]-'0',b1=s1[1]-'0',b2=s2[1]-'0';
	if (c1==c2&&a1==a2&&b1==b2) cout << 1;
	else cout << 0;
	
	if (c1==c2&&a1==a2&&b1==b2) {
		if (s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')||
			s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')||
			s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B')||
			s1[2]=='D'&&s2[2]=='F'||
			s1[2]=='F'&&s2[2]=='D') cout << 1;
		else cout << 0;
	} 
	else cout << 0;
	
	if (c1==c2&&a1==a2&&b1==b2) {
		if (s1[2]=='A'&&s2[2]=='B'||
			s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')||
			s1[2]=='C'&&s2[2]=='B'||
			s1[2]=='D'&&s2[2]=='F'||
			s1[2]=='F'&&s2[2]=='D') cout << 1;
		else cout << 0;
	}
	else cout << 0;
	return 0;
}
