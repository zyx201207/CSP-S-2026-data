#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	char b,d;
	string x,y;
	cin >> a >> x>> c >> y;
	b = x[3];
	d = y[3];
	int t = 1;
	if(a == c) 
	t = 1;		
	cout << t;
	if(t == 1){
		if(x[1] == y[1] && x[0] == y[0])
		t = 1;
		else t = 0;
	}
	cout <<t;
	if(t == 1){
		if(b == 'A' && d == 'B') t = 1;
		else if(b == 'A' && b == 'C') t = 1;
		else if(b == 'B' && b == 'C') t = 1;
		else if(b == 'D' && b == 'E') t = 1;
		else if(b == 'C' && b == 'B') t = 1;
		else if(b == 'C' && b == 'A') t = 1;
		else if(b == 'E' && b == 'D') t = 1;
		else if(b == 'B' && b == 'A') t = 1;
		else t = 0;
	}
	cout << t;
	if(b - 'C' != 0 && b-'D' != 0 && d-'C' != 0 && d-'C' != 0){
		if(b-d == 1) 
		t = 1;
		else if(d-b == 1)
		t = 1;
		else t = 0;
	}
	cout << t;
	return 0;
} 
