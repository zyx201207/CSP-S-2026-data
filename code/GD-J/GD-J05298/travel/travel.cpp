#include<bits/stdc++.h>
using namespace std;

bool check(char a, char b){
	if(a == 'A' || a == 'B' || a == 'C'){
		return b == 'A' || b == 'B' || b == 'C';
	}
	return b == 'D' || b == 'F';
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string R, X, RH, XH;
	cin >> R >> RH >> X >> XH;
	if(R != X){cout << "0000"; return 0;}
	int r = 0, x = 0;
	for(int i = 0; i < 2; i++){
		r += RH[i] - '0';
		x += XH[i] - '0';
	}
	if(r != x){cout << "1000"; return 0;}
	char a = RH[2], b = XH[2];
	if(!check(a, b)){cout << "1100"; return 0;}
	if(abs(a - b) != 1){cout << "1110"; return 0;}
	cout << "1111";
	return 0;
} 
