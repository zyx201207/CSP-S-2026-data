#include<bits/stdc++.h>
using namespace std;
int main(){
	int r,x;
	string r1,x1;
	cin >> r >> r1 >> x >> x1;
	if (r == x){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if (r1[0] == x1[0] && r1[1] == x1[1]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if ('A' <= r1[2] <= 'C' && 'A' <= x1[2] <= 'C' || 'D' <= r1[2] <= 'F' && 'D' <= x1[2] <= 'F'){
		cout << 1; 
	} 
	else{
		cout << 0;
	}
	if(r1[2] - x1[2] == 1 || x1[2] - r1[2] == 1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
