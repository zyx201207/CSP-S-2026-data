#include<bits/stdc++.h>
using namespace std;
struct cx{
	string cxh;
	string zwh;
}xr , xx;

bool cx(string a , string b){
	int c , d;
	c = a[0] * 10 + a[1];
	c = c - 48 * 10 - 48;
	d = b[0] * 10 + b[1];
	d = d - 48 * 10 - 48;
	if(c == d){
		return true;
	}else{
		return false;
	}
}
bool tp(string a , string b){
	int c , d;
	c = a[0] * 10 + a[1];
	c = c - 48 * 10 - 48;
	d = b[0] * 10 + b[1];
	d = d - 48 * 10 - 48;
	if(c == d){
		return true;
	}else{
		return false;
	}
}
bool tc(string a , string b){
	char c , d;
	c = a[2];
	d = b[2];
	if(c == 'A' && d == 'B'){
		return true;
	}else if(c == 'A' && d == 'C'){
		return true;
	}else if(c == 'C' && d == 'A'){
		return true;
	}else if(c == 'B' && d == 'A'){
		return true;
	}else if(c == 'B' && d == 'C'){
		return true;
	}else if(c == 'C' && d == 'B'){
		return true;
	}else if(c == 'D' && d == 'F'){
		return true;
	}else if(c == 'F' && d == 'D'){
		return true;
	}else{
		return false;
	}
}
bool xl(string a , string b){
	int c , d;
	char e , f;
	c = a[0] * 10 + a[1];
	c = c - 48 * 10 - 48;
	d = b[0] * 10 + b[1];
	d = d - 48 * 10 - 48;
	e = a[2];
	f = b[2];
	if(e == f){
		if(c = d + 1){
			return true;
		}else if(d = c + 1){
			return true;
		}else{
			return false;
		}
	}else if(e == 'A' && f == 'B' || e == 'A' && f == 'B'){
		if(c == d){
			return true;
		}else{
			return false;
		}
	}else if(e == 'B' && f == 'C' || e == 'C' && f == 'B'){
		if(c == d){
			return true;
		}else{
			return false;
		}
	}else if(e == 'D' && f == 'F' || e == 'F' && f == 'D'){
		if(c == d){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> xr.cxh >> xr.zwh >> xx.cxh >> xx.zwh;
	if(cx(xr.cxh , xx.cxh)){
		cout << "1";
		if(tp(xr.zwh , xx.zwh)){
			cout << 1;
			if(tc(xr.zwh , xx.zwh)){
				cout << 1;
				if(xl(xr.zwh , xx.zwh)){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << 0;
				if(xl(xr.zwh , xx.zwh)){
					cout << 1;
				}else{
					cout << 0;
				}
			}
		}else{
			cout << "00";
			if(xl(xr.zwh , xx.zwh)){
				cout << 1;
			}else{
				cout << 0;
			}
		}
	}else{
		cout << "0000";
		return 0;
	}
	return 0;
}

