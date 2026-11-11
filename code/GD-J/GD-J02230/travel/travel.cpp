#include <bits/stdc++.h> 
using namespace std;
string r1, r2, x1, x2;
bool check(){
	int numr = (r2[0] - '0') * 10 + (r2[1] - '0'), numx = (x2[0] - '0') * 10 + (x2[1] - '0');
	if (abs(numr - numx) > 1){
		return false;
	}
	if (abs(numr - numx) == 0){
		char r = r2[2], x = x2[2];
		int tr = r, tx = x;
		if (abs(tr - tx) == 1 && (r != 'C' && x != 'D') && (r != 'D' && x!= 'C')){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r1 >> r2 >> x1 >> x2;
	int numr = (r2[0] - '0') * 10 + (r2[1] - '0'), numx = (x2[0] - '0') * 10 + (x2[1] - '0');

	
	
	if (r1 == x1){
		cout << 1;
	} else cout << 0;
	
	if (r2 == x2){
		cout << 0 << 0 << 0;
		return 0;
	}
	
	if (numr == numx){
		cout << 1;
	} else cout << 0;
	
	if (numr == numx && (r2[2] <= 'C' && x2[2] <= 'C' || r2[2] >= 'D' && x2[2] >= 'D')){
		cout << 1;
	} else cout << 0;
	
	if (check()){
		cout << 1;
	} else cout << 0;
	return 0;
}
