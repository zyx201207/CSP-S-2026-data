#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int x[5];
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) {
		cout << 1;
		x[1]=1;
	}
	else {
		cout << 0;
		x[1]=0;
	}
	int a1 = s1[0]*10 + s1[1];
	int b1 = s2[0]*10 + s2[1];
	if(c1==c2 && a1==b1) {
		cout << 1;
		x[2]=1;
	}
	else {
		cout << 0;
		x[2]=0;
	}
	int a = s1[2], b = s2[2];
	if(c1==c2 && a1==b1 && (a<=67&&b<=67 || a>67&&b>67)) {
		cout << 1;
		x[3]=1;
	}
	else {
		cout << 0;
		x[3]=0;
	}
	if(c1==c2 && a1==b1 && abs(a-b)==1) {
		if(a==67&&b==68 || a==68&&b==67) {
			cout << 0;
		}	
		else cout << 1;
	}
	else cout << 0;
	
	return 0;
}
