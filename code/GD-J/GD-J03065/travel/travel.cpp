#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2;
	string s1, s2;
	int a, b, c;
	cin >> c1 >> s1;
	cin >> c2 >> s2;
	a = s1[2] - 'A';
	b = s2[2] - 'A';
	c = 'D' - 'A';
	if(c1 == c2){
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			if((a < c && b < c) || (a >= c && b >= c)){
				cout << 1;
				if(a + 1 == b || a - 1 == b) cout << 1;
				else cout << 0;
			} 
			else cout << "00";
		} 
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
