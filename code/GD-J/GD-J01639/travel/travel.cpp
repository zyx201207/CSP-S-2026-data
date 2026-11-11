#include <bits/stdc++.h>
using namespace std;
int pos[555];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	pos['A'] = pos['B'] = pos['C'] = 1;
	pos['D'] = pos['F'] = 2;
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3) cout << 1;
	else {cout << "0000";return 0;}
	if(s2[0] == s4[0] && s2[1] == s4[1]) cout << 1;
	else {cout << "000";return 0;}
	if(pos[s2[2]] == pos[s4[2]]) cout << 1;
	else {cout << "00";return 0;}
	if(pos[s2[2]] == 2 || s2[2] + 1 == s4[2] || s2[2] - 1 == s4[2]) cout << 1;
	else cout << 0;
	return 0;
}
