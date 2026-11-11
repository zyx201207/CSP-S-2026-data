#include <bits/stdc++.h>
using namespace std;

int op1, op2;
string x, y;
int a[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> op1 >> x >> op2 >> y;
	
	if(op1 == op2) a[1] = 1;
	if(a[1]) {
		a[2] = 1;
		for(int i = 0; i <= 1; i ++) {
			if(x[i] != y[i]) a[2] = 0;
		}
		
		if(a[2]) {
			if((x[2] > 'C' && y[2] > 'C') || (x[2] < 'D' && y[2] < 'D')) a[3] = 1;
			if(!a[3]){ }
			else if((x[2] == (char)y[2] + 1) || (x[2] == (char)y[2] - 1)) a[4] = 1;
		}
	}
	
	for(int i = 1; i <= 4; i ++) {
		cout << a[i];
	}
	
	return 0;
} 
