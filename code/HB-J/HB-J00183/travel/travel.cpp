#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string colm1,colm2,str1,str2;
	cin >> colm1 >> str1 >> colm2 >> str2;
	if(colm1 == colm2)cout << 1;
	else {cout << "0000";return 0;}
	if(str1[0] == str2[0] && str1[1] == str2[1])cout << 1;
	else {cout << "000";return 0;}
	if(('A' <= str1[2] && str1[2] <= 'C' && 'A' <= str2[2] && str2[2] <= 'C') || (('D' == str1[2] || str1[2] == 'F') && ('D' == str2[2] || str2[2] == 'F')))cout << 1;
	else {cout << "00";return 0;}
	switch(str1[2]){
		case 'A':	if(str2[2] == 'B')cout << 1;
					else cout << 0;
					break;
		case 'B':	if(str2[2] == 'A' || str2[2] == 'C')cout << 1;
					else cout << 0;
					break;
		case 'C':	if(str2[2] == 'B')cout << 1;
					else cout << 0;
					break;
		case 'D':	if(str2[2] == 'F')cout << 1;
					else cout << 0;
					break;
		case 'F':	if(str2[2] == 'D')cout << 1;
					else cout << 0;
					break;
	}
	return 0;
}
