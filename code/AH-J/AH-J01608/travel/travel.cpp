#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a == c) cout << 1;
	else cout << 0;
	if((a == c) && (b[0] == d[0]) && (b[1] == d[1])) cout << 1;
	else cout << 0;
	int p = b[2] - 'A' + 1, q = d[2] - 'A' + 1;
	if((((p <= 3) && (q <= 3)) || ((p >= 4) && (q >= 4))) && (a == c) && (b[0] == d[0]) && (b[1] == d[1]))  
		cout << 1;
	else cout << 0;
	if((a == c) && (b[0] == d[0]) && (b[1] == d[1])){
		if((p <= 3) && (q <= 3)){
			if(abs(p - q) == 1) cout << 1;
			else cout << 0;
		}
		if((p >= 4) && (q >= 4)){
			if(p == 4 && q == 6) cout << 1;
			else cout << 0;
		}
		if(!(((p <= 3) && (q <= 3)) || ((p >= 4) && (q >= 4)))) cout << 0;
	}
	else cout << 0;
	return 0;
} 
