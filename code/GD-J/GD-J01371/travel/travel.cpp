#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1, s1, c2, s2;
bool side1, side2;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	cout << "1";
	if(!((s1[0] == s2[0]) && (s1[1] == s2[1]))){
		cout << "000";
		return 0;
	}
	cout << "1";
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')	side1 = 1;
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')	side2 = 1;
	if(side1 != side2){
		cout << "00";
		return 0;
	}
	cout << "1";
	if(abs((int)(s1[2] - s2[2])) != 1){
		cout << "0";
		return 0;
	}
	cout << "1";
	
	
	return 0;
}
