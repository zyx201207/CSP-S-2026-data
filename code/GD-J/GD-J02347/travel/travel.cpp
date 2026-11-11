#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ax,az,bx,bz;
	cin >> ax >> az >> bx >> bz;
	if(ax == bx) cout << 1;
	else{
		cout << "0000";
		return 0; 
	}
	string p1 = az.substr(0,2);
	string p2 = bz.substr(0,2);
	if(p1 == p2) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	int f1,f2;
	if(az[2] == 'A' || az[2] == 'B' || az[2] == 'C') f1 = 1;
	else f1 = 2;
	if(bz[2] == 'A' || bz[2] == 'B' || bz[2] == 'C') f2 = 1;
	else f2 = 2;
	if(f1 == f2) cout << 1;
	else{
		cout << "00";
		return 0; 
	}
	if( abs( (int)az[2] - (int)bz[2] ) == 1) cout << 1;
	else cout << 0;
	return 0;
} 
