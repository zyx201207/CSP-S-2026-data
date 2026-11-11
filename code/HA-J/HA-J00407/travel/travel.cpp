#include<bits/stdc++.h>
using namespace std;

string a, b, c, d;


int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	
	cin >> a >> c >> b >> d;

	if(a == b) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	
	if(c[0] == d[0] && c[1] == d[1]) cout << "1";
	else{
		cout << "000";
		return 0;
	}
	
	if(c[2] <= 'C' && d[2] <= 'C' || c[2] > 'C' && d[2] > 'C') cout << "1";
	else{
		cout << "00";
		return 0;
	}
	
	if(abs((c[2] - 'A') - (d[2] - 'A')) == 1) cout << "1";
	else cout << "0";
	
	
	return 0;
}
