#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a, b, g, h;
	string c, d;
	char e, f;
	cin >> a >> c >> b >> d;
	if(a == b){
		cout << '1';
	}
	else{
		cout << "0000";
		return 0;
	}
	if(c[0] == d[0]&&c[1] == d[1]){
		cout << '1';
	}
	else{
		cout << "000";
		return 0;
	}
	if(c[2] == 'A'){
		if(d[2] == 'B'){
			cout << '1';
		}
		else{
			if(d[2] == 'C'){
				cout << '1';
			}
		}
	}
	if(c[2] == 'B'){
		if(d[2] == 'A'){
			cout << '1';
		}
		else{
			if(d[2] == 'C'){
				cout << '1';
			}
		}
	}
	if(c[2] == 'C'){
		if(d[2] == 'A'){
			cout << '1';
		}
		else{
			if(d[2] == 'B'){
				cout << '1';
			}
		}
	}
	if(c[2] == 'D'){
		if(d[2] == 'E'){
			cout << '1';
		}
	}
	if(c[2] == 'E'){
		if(d[2] == 'D'){
			cout << '1';
		}
	}
	e = c[2];
	f = d[2];
	if(e == 'C'&& f == 'D'){
		cout << "00";
		return 0;
	}
	if(e == 'D'&& f == 'C'){
		cout << '0';
		return 0;
	}
	g = (int(e));
	h = (int(f));
	if(g == h+1||g == h-1){
		cout << "00";
	}
	return 0;
}
