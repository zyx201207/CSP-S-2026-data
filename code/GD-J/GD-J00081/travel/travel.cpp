#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s,c;
	cin >> a >> s >> b >> c;
	if(a == b) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	int n,m;
	n = (s[0] - '0') * 10 + s[1] - '0';
	m = (c[0] - '0') * 10 + c[1] - '0';
	if(n == m) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	char c1 = s[2],c2 = c[2];
	if((c1 >= 'A' && c1 <= 'C' && c2 >= 'A' && c2 <= 'C') || (c1 >= 'D' && c1 <= 'F' && c2 >= 'D' && c2 <= 'F'))
		cout << 1;
	else{
		cout << "00";
		return 0;
	}
	int x = abs(c1 - c2);
	if(x == 1) cout << 1;
	else if(x > 1){
		if(c1 >= 'D' && c2 >= 'D') cout << 1;
		else cout << 0;
	}
	return 0;
}
