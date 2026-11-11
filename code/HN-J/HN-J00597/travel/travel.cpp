#include<bits/stdc++.h>
using namespace std;
string a , b , c , d;
char x , y;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	cin >> a >> b >> c >> d;
	x = b[b.size() - 1] , y = d[d.size() - 1];
	if(a != c){
		cout <<"0000";
		return 0;
	}
	bool h = 1;
	for(int i = 0;i < 2;i++){
		if(b[i] != d[i]){
			h = 0;
			break;
		}
	}
	if(!h){
		cout << 1000;
		return 0;
	}
	if(x >= 'A' && x <= 'C'){
		if(y >= 'D') h = 0;
	}else{
		if(y <= 'C') h = 0;
	}
	if(!h){
		cout << 1100;
		return 0;
	}
	if(char(x + 1) == y || char(x - 1) == y){
		cout << 1111;
	}else{
		cout << 1110;
	}
	return 0;
} 
