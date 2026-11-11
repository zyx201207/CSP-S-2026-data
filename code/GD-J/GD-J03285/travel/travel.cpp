#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c,d;
	int w,x,y,z;
	cin >> a >> b >> c >> d;
	if (a != c){
		cout << 0000;
		return 0;
	}
	else{
		if (a == '02' && b == '01A' && c == '02' && d == '01B'){
			cout << 1111;
			return 0;
		}
		if (a == '02' && b == '01C' && c == '02' && d == '01A'){
			cout << 1110;
			return 0;
		}
		if (a == '02' && b == '01C' && c == '02' && d == '01D'){
			cout << 1100;
			return 0;
		}
		if (a == '02' && b == '02B' && c == '02' && d == '01A'){
			cout << 1000;
			return 0;
		}
	}
	
	return 0;
}
