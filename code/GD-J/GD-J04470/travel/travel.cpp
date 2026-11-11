#include <bits\stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q,w,e,r;
	cin >> q >> w >> e >> r;
	if(q == e) { 
		cout << 1;
	if(w[0] - r[0] == 0 && w[1] - r[1] == 0 && w[2] != r[2]){
		cout << 1;
	if(w[2] <= 'C' && r[2] <= 'C'){
		cout << 1;
	}else if(w[2] >='D' && r[2] >= 'D'){
		cout << 1;
	}else{
		cout << 0;
	}if(w[2] + 1 == r[2] && w[2] < 'C'){
		cout << 1;
	}else if(w[2]-1 == r[2] && w[2] <'D' ){
		cout << 1;
	} else if(w[2] == 'F' && r[2] == 'D'){
		cout << 1;
	}else{
		cout << 0;
	}}else{
		cout << "000";
	}
	}else{
		cout << "0000";
	}
	
	return 0;
}
