#include <bits/stdc++.h> 
using namespace std;

int main() {
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,b,c,d,s="0000";
	int n = 0;
	cin >> a >> b >> c >> d;
	
	if (a == c) s[0]='1';
	else {
		cout << s;
		return 0;
	}
	
	if (b[0] == d[0] && b[1] == d[1]) s[1] = '1';
	else {
		cout << s;
		return 0;
	}
	
	if (b[2] <= 'C' && d[2] <= 'C'){
		s[2] = '1';
		n = 1;	
	} else if (b[2] >= 'D' && d[2] >= 'D'){
		s[2] = '1';
		n = 2;
	} else { 
	cout << s;
	return 0;
	}
	
	if (n != 0) {
		if (n == 2) s[3] = '1';
		else if (b[2] == 'B' || d[2]== 'B') s[3] = '1';
		else {
			cout << s;
			return 0;
		}
	} else {
		cout << s;
		return 0;
	}
	cout << s;
	return 0;
}
