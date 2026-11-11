#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;

inline bool eqc(const char& ss1) {
	return (ss1 == 'A' || ss1 == 'B' || ss1 == 'C');
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	cout << (bool)(c1==c2);
	cout << (bool)(c1==c2 && s1[0] == s2[0] && s1[1] == s2[1]);
	cout << (bool)(c1==c2 && s1[0] == s2[0] && s1[1] == s2[1] && (eqc(s1[2]) == eqc(s2[2])
	));
	cout << (bool)(c1==c2 
	&& s1[0] == s2[0] 
	&& s1[1] == s2[1] 
	&& (eqc(s1[2]) == eqc(s2[2]))
	&& ((char)s1[2])+1 == (char)s2[2]);	
	return 0;
} 
