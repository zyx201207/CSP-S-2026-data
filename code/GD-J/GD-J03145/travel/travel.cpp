#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	
	string c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2) cout << 1;
	else {
		cout << "0000" << endl;
		return 0;
	}
	
	if(s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else {
		cout << "000" << endl;
		return 0;
	}
	
	int seat1 = s1[2] - 'A';
	int seat2 = s2[2] - 'A';
	if((seat1 <= 2 && seat2 <= 2) || (seat1 >= 3 && seat2 >= 3)) cout << 1;
	else {
		cout << "00" << endl;
		return 0;
	}
	
	if(abs(seat1 - seat2) == 1) {
		if(seat1 == 2 && seat2 == 3) cout << 0 << endl;
		else if(seat1 == 3 && seat2 == 2) cout << 0 << endl;
		else cout << 1 << endl;
	} else cout << 0 << endl;
	
	return 0;
} 
