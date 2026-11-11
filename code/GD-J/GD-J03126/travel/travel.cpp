#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a[0] != c[0] || a[1] != c[1]){
		cout << "0000";
		return 0;
	}
	if(b[0] != d[0] || b[1] != d[1]){
		cout << "1000";
		return 0;
	}
	if(b[2] == 'A' || b[2] == 'B' || b[2] == 'C'){
		if(d[2] != 'A' && d[2] != 'B' && d[2] != 'C'){
			cout << "1100";
			return 0;
		}
	}
	else{
		if(d[2] != 'D' && d[2] != 'E'){
			cout << "1100";
			return 0;
		}
	}
	bool ok = true;
	if(b[2] == 'A'){
		if(d[2] != 'B'){
			ok = false;
		}
	}
	else if(b[2] == 'B'){
		if(d[2] != 'A' && d[2] != 'C'){
			ok = false;
		}
	}
	else if(b[2] == 'C'){
		if(d[2] != 'B'){
			ok = false;
		}
	}
	else if(b[2] == 'D'){
		if(d[2] != 'E'){
			ok = false;
		}
	}
	else{
		if(d[2] != 'D'){
			ok = false;
		}
	}
	if(ok){
		cout << "1111";
	}
	else{
		cout << "1110";
	}
	return 0;
}
