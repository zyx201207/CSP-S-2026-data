#include <bits/stdc++.h>
//#define int long long
using namespace std;
string c1,s1,c2,s2;
bool jg1 = 0,jg2 = 0,jg3 = 0;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[1] == c2[1] && c1[2] == c2[2]){
		cout << 1;
		jg1 = 1;
	}
	else
		cout << 0;
	if(jg1 && s1[0] == s2[0] && s1[1] == s2[1]){
		cout << 1;
		jg2 = 1;
	}
	else
		cout << 0;
	if(jg2)
		if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
			cout << 1;
			jg3 = 1;
		}
		else
			cout << 0;
	else if(!jg2)
		cout << 0;
	if(jg3){
		int m1 = s1[2],m2 = s2[2];
		if((m1 - m2 == 1) || (m1 - m2 == -1))
			cout << 1;
		else
			cout << 0;
	}
	else if(!jg3)
		cout << 0;
	return 0;
}
