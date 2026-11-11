#include <bits/stdc++.h>
using namespace std;

int f;
string a, b, c, d;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
	} else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if(b[0]+b[1] == d[0]+d[1]){
		cout << 1;
	} else {
		cout << 0 << 0 << 0;
		return 0;
	}
	if(b[2] == 'A'){
		if(d[2] == 'B' || d[2] == 'C'){
			f = 1;
		}
	} 
	if(b[2] == 'B'){
		if(d[2] == 'A' || d[2] == 'C'){
			f = 1;
		}
	} 
	if(b[2] == 'C'){
		if(d[2] == 'B' || d[2] == 'A'){
			f = 1;
		}
	} 
	if(b[2] == 'D'){
		if(d[2] == 'F'){
			f = 1;
		}
	} 
	if(b[2] == 'F'){
		if(d[2] == 'D'){
			f = 1;
		}
	} 
	cout << f;
	f = 0;
	if(b[2] == 'A'){
		if(d[2] == 'B'){
			f = 1;
		}
	} 
	if(b[2] == 'B'){
		if(d[2] == 'A' || d[2] == 'C'){
			f = 1;
		}
	} 
	if(b[2] == 'C'){
		if(d[2] == 'B'){
			f = 1;
		}
	} 
	if(b[2] == 'D'){
		if(d[2] == 'F'){
			f = 1;
		}
	} 
	if(b[2] == 'F'){
		if(d[2] == 'D'){
			f = 1;
		}
	} 
	cout << f;
	return 0;
}
