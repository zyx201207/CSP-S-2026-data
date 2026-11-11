#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, aa, bb;
	cin >> a >> b >> aa >> bb;
	if(a != aa){
		cout << "0000";
		return 0;
	}
	else cout << 1;
	bool hhh = 1;
	for(int i = 0; i < 2; i ++){
		if(b[i] != bb[i]) hhh = 0;
	}
	if(hhh){
		cout << 1;
	}
	else{
		cout << "000";
		return 0;
	}
	if(b[2] <= 'C' && bb[2] <= 'C' && b[2] >= 'A' && bb[2] >= 'A'){
		cout << 1;
	}
	else if(b[2] >= 'D' && bb[2] >= 'D'){
		cout << "11";
		return 0;
	}
	else{
		cout << "00";
		return 0;
	}
	if(abs(b[2] - bb[2]) == 1){
		cout << 1;
	}
	else{
		cout << 0; 
	}
	return 0; 
}
