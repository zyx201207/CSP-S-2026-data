#include<bits/stdc++.h>
using namespace std;
string a , b, c , d;
string b1 , d1 , b2 , d2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	for(int i = 0 ; i < 2; i++){
		b1 += b[i];
		d1 += d[i];
	}
	if(b1 == d1){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	b2 += b[2];
	d2 += d[2];
	if((b2 == "C" && d2 == "D") || (b2 == "D" && d2 == "C")){
		cout << "00";
		return 0;
	}else{
		cout << 1;
	}
	char x = b[2];
	char y = d[2];
	if(x + 1 == y || x - 1 == y || y + 1 == x || y - 1 == x){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
