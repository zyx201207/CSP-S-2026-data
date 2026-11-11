#include<bits/stdc++.h>
using namespace std;
string a , b , c , d;
int main() {
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	if(a != c) {
		cout << "0000";
		return 0;
	} 
	cout << 1;
	string b1 = b.substr(0 , 2);
	string d1 = d.substr(0 , 2);
	if(b1 == d1) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	if(b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C') {
		int x = b[2] - 'A';
		int y = d[2] - 'A';
		if(abs(x - y) == 1) cout << 11; 
		else cout << 10;
	}
	else if(b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F') {
	cout << 11;
	}else {
		cout << "00";
		return 0; 
	}
	return 0;
}
