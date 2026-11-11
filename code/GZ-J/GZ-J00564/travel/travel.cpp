//GZ-J00564  毕节七星关东辰实验学校  李浩辰 

#include<bits/stdc++.h>
using namespace std;
string Rz, R, Xz, X;
long long rz, r, xz, x;
char c, s;
bool t;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> Rz >> R >> Xz >> X;
	for(int i = 0; i < Rz.size(); i++) rz += Rz[i] - '0';
	for(int i = 0; i < Xz.size(); i++) xz += Xz[i] - '0';
	for(int i = 0; i < R.size() - 1; i++) r += R[i] - '0';
	for(int i = 0; i < X.size() - 1; i++) x += X[i] - '0';
	c = R[R.size() - 1];
	s = X[X.size() - 1];
	if(rz != xz){
		cout << "0000";
		return 0;
	}else cout << "1";
	if(r == x){
		cout << "1";
		t = true;
	}
	else cout << "0";
	if(c >= 'A' && c <= 'C'){
		if(s >= 'A' && s <= 'C' && t) cout << "1";
		else cout << "0";
	}else{
		if(s == 'E' || s == 'F' && t) cout << "1";
		else cout << "0";
	}
	if((c == 'A' && s == 'B') || (c == 'B' && s == 'C') || (c == 'C' && s == 'B') || (c == 'D' && s == 'F') || (c == 'F' && s == 'D')) cout << "1";
	else cout << "0";
	return 0;
}
