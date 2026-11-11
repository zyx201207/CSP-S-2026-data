#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	bool sum = false;
	if(a == c){
		cout << "1";
		sum = true;
	}
	else{
		cout << "0";
	}
	if(!sum){
		cout << "000";
		return 0;
	}
	bool flag = true,ans = false;
	for(int i = 0; i < 2; i++){
		if(b[i] != d[i]){
			flag = false;
			break;
		}
	}
	if(flag){
		cout << "1";
	}
	else{
		cout << "000";
		return 0;
	}
	if(flag){
		if((b[2] >= 'A' && b[2] <= 'C'&& d[2] >= 'A' && d[2] <= 'C') || (b[2] >= 'D' && b[2] <= 'E'&& d[2] >= 'D' && d[2] <= 'E')){
			ans = true;
		}
		if(ans){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	if((b[2] == 'D' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'D')){
		cout << "0";
		return 0;
	}
	if(abs(d[2] - b[2]) == 1){
		cout << "1";
		return 0;
	}
	cout << "0";
	return 0;
} 
