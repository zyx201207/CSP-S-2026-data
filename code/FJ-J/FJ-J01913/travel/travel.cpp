#include <bits/stdc++.h>
using namespace std;

string xiang1,xiang2,zuo1,zuo2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> xiang1 >> zuo1 >> xiang2 >> zuo2;
	if(xiang1 == xiang2){
		cout << 1;
	}
	else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if(zuo1[0] == zuo2[0] && zuo1[1] == zuo2[1]){
		cout << 1;
	}
	else{
		cout << 0 << 0 << 0;
		return 0;
	}
	if(((zuo1[2] == 'A' || zuo1[2] == 'B' || zuo1[2] == 'C') && (zuo2[2] == 'A' || zuo2[2] == 'B' || zuo2[2] == 'C')) || ((zuo1[2] == 'D' || zuo1[2] == 'F' ) && (zuo2[2] == 'D' || zuo2[2] == 'F'))){
		cout << 1;
	}
	else{
		cout << 0 << 0;
		return 0;
	}
	if((zuo1[2] == 'A' && zuo2[2] == 'C') || (zuo1[2] == 'C' && zuo2[2] == 'A')){
		cout << 0;
	}
	else{
		cout << 1;
	}
	return 0;
}
