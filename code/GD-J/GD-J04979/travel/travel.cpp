#include<bits/stdc++.h>
using namespace std;

int a, b;
string c, d;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> c >> b >> d;
	if(a == b) cout << 1;
	else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if(c.substr(0, 2) == d.substr(0, 2)) cout << 1;
	else{
		cout << 0 << 0 << 0;
		return 0;
	}
	if((c[2] <= 'C' && d[2] > 'C') || (d[2] <= 'C' && c[2] > 'C')){
		cout << 0 << 0;
	}else{
		cout << 1;
		if(abs(c[2] - d[2]) == 1) cout << 1;
		else cout << 0;
	}
	return 0;
} 
