#include<bits/stdc++.h>
using namespace std;
int xs , ys;
string x1 , x2 , z1 , z2;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> x1 >> x2 >> z1 >> z2;
	//cout << x1 << z1;
	for(int i = 0;i < 2;i++){
		xs += (x1[i] - '0') * 10;
		ys += (z1[i] - '0') * 10;
	}
	if(xs != ys){
		cout << "0000";
		return 0;
	}
	cout << "1";
	for(int i = 0;i < 2;i++){
		xs += (x2[i] - '0') * 10;
		ys += (z2[i] - '0') * 10;
	}
	if(xs != ys){
		cout << "000";
		return 0;
	}
	cout << "1";
	if((x2[2] <= 'C' && z2[2] > 'C') || (z2[2] <= 'C' && x2[2] > 'C')){
		cout << "00";
		return 0;
	}
	cout << "1";
	if(abs(x2[2] - z2[2]) > 1){
		cout << "0";
		return 0;
	}
	cout << "1";
	return 0;
} 
