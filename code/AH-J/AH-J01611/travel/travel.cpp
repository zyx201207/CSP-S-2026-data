#include<bits/stdc++.h> 
using namespace std;
int val (char a){
	if (a == 'A') return 1;
	else if (a == 'B') return 2;
	else if (a == 'C') return 3;
	else if (a == 'D') return 9;
	else if (a == 'F') return 10;
}
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1 == c3) cout << 1;
	else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if (c2[0] == c4[0] && c2[1] == c4[1]) cout << 1;
	else cout << 0;
	if(abs ((val(c2[2])) - (val(c4[2]))) <= 2) cout << 1;
	else cout << 0;
	if(abs ((val(c2[2])) - (val(c4[2]))) == 1) cout << 1;
	else cout << 0;
	return 0;
}
