#include<iostream>
using namespace std;
int main(){
	string c1, c2, c3, c4;
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1 == c3){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(c2[0] == c4[0] && c4[1]==c2[1]){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	int c5,c6;
	if(c2[2]>=65||c2[2]<=67){
		c5 = 0;
	}else{
		c5 = 1;
	}
	if(c4[2]>=65||c4[2]<=67){
		c6 = 0;
	}else{
		c6 = 1;
	}
	if(c5 == c6){
		cout << 1;
	}else{
		cout << "00";
		return 0;
	}
	if(c2[2]+1==c4[2] || c2[2]-1 == c4[2] || c5 == 0){
		cout << 1;
	}else{
		cout << "0";
	}
} 
