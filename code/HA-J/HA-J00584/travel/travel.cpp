#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1 , c2 , s1 , s2 , ss1 , ss2 , cc1 ,  cc2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << '1';
	else cout << '0';
	ss1 = s1[0] + s1[1];
	ss2 = s2[0] + s2[1];
	if(ss1 == ss2 && c1 == c2) cout << "1";
	else cout << "0";
	if(c1 == c2 && ss1 == ss2 && s1[2] >= 'D' && s2[2] >= 'D') cout << "1";
	else if(c1 == c2 && ss1 == ss2 && s1[2] < 'D' && s2[2] < 'D') cout << "1";
	else cout << "0";
	if(ss1 == ss2 && c1 == c2 && s1[2] >= 'D' && s2[2] >= 'D') cout << "1";
	else if(ss1 == ss2 && c1 == c2 && s1[2] < 'D' && s2[2] < 'D'){
		if(char(s1[2] + 1) == s2[2] || char(s2[2] + 1 == s1[2])) cout << "1";
		else cout << "0";
	}
	else cout << "0";
	return 0;
}
