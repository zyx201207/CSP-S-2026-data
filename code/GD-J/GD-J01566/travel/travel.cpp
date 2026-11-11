#include<bits/stdc++.h>
using namespace std;
int a , b , ap , bp , az , bz;
string aa , bb;
void f(){
	ap = (aa[0] - '0') * 10 + (aa[1] - '0');
	bp = (bb[0] - '0') * 10 + (bb[1] - '0');
	az = aa[2] - 'A' + 1;
	bz = bb[2] - 'A' + 1;
}
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> a >> aa >> b >> bb;
	if(a == b){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	f();
	if(ap == bp){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if(az <= 3 && bz <= 3 || az > 3 && bz > 3){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	if((int)abs(az - bz) == 1){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
