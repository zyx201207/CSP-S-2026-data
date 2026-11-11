#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int cr=0,cx=0;
	int zr=0,zx=0;
	char xr,xx;
	cin >> cr >> zr >> xr;
	cin >> cx >> zx >> xx;
	if(cr==cx){
		cout << '1';
	}else{
		cout << "0000";
		return 0;
	}
	if(zr==zx){
		cout << '1';
	}else{
		cout << "000";
		return 0;
	}
	if(xr>='A' && xr<='C' && xx>='A' && xx<='C'){
		cout << '1';
	}else if(xr>='D' && xr<='F' && xx>='D' && xx<='F'){
		cout << '1';
	}else{
		cout << "00";
		return 0;
	}
	if(xr=='C' && xx=='D'){
		cout << '0';
	}else if(xr=='D' && xx=='C'){
		cout << '0';
	}else if(abs(xr-xx)==1){
		cout << '1';
	}else{
		cout << '0';
	}
	return 0;
} 
