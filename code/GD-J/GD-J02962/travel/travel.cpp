#include <bits/stdc++.h>
#define int long long
using namespace std;

int check (char a){
	return (a == 'A' || a == 'B' || a == 'C');
}

int num (char a){
	if (a == 'A') return 1;
	if (a == 'B') return 2;
	if (a == 'C') return 3;
	if (a == 'D') return 5;
	if (a == 'F') return 6;
	return 0;
}

signed main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	
	int xc,xh,yc,yh;
	char xs,ys;
	cin >> xc >> xh >> xs >> yc >> yh >> ys;
	
	cout << (xc == yc);
	cout << (xc == yc && xh == yh);
	cout << (xc == yc && xh == yh && check (xs) == check (ys));
	cout << (xc == yc && xh == yh && abs (num (xs) - num (ys)) == 1);
	return 0;
}

