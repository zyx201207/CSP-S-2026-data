#include<bits/stdc++.h>
using namespace std;

string R, r, X, x;//表示小R的车票上的车厢号、座位号，以及小X的车票上的车厢号、座位号

bool tong(char a, char b){
	if (a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C'){
		return true;
	}
	if (a >= 'D' && a <= 'E' && b >= 'D' && b <= 'E'){
		return true;
	}
	return false;
}



int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio;
	cin.tie(0), cout.tie(0);
	
	cin >> R >> r >> X >> x;
	
	if (R == X){
		cout << "1";
		if ((r[0] - '0')== (x[0] - '0') && (r[1] - '0') == (x[1] - '0')){
			cout << "1";
			if (tong(r[2], x[2])){
				cout << "1";
				if (r[2] == 'D' && x[2] == 'E'||r[2] == 'E' && x[2] == 'D') cout << "1";
				else if (r[2] == 'A' && x[2] == 'B'||r[2] == 'B' && x[2] == 'A') cout << "1";
				else if (r[2] == 'B' && x[2] == 'C'||r[2] == 'C' && x[2] == 'B') cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	} 
	else cout << "0000";
	return 0;
}
