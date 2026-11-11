#include<bits/stdc++.h>
using namespace std;

int a, b;
char x[3], y[3], xx[4], yy[4];

int main(){
	freopen( "travel.in", "r", stdin );
	freopen( "travel.out", "w", stdout );
	cin >> x[1] >> x[2] >> xx[1] >> xx[2] >> xx[3];
	cin >> y[1] >> y[2] >> yy[1] >> yy[2] >> yy[3];
	bool f = true;
	for( int i = 1; i <= 2; i++ ){
		if( x[i] != y[i] ){
			f = false;
		}
	}
	if( f == true ){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	for( int i = 1; i <= 2; i++ ){
		if( xx[i] != yy[i] ){
			f = false;
		}
	}
	if( f == true ){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if( xx[3] <= 'C' && xx[3] >= 'A' && yy[3] <= 'C' && yy[3] >= 'A' ){
		cout << 1;
	}else if( xx[3] <= 'F' && xx[3] >= 'D' && yy[3] <= 'F' && yy[3] >= 'D' ){
		cout << 1;
	}else{
		cout << "00";
		return 0;
	}
	if( xx[3] - yy[3] == 1 || yy[3] - xx[3] == 1 ){
		cout << 1;
	}else{
		cout << "0";
	}
	return 0;
}
