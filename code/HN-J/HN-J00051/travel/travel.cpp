#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >>d;
	if(a==c) cout << 1;
	else cout << 0;
	if(b[1]=d[1]) cout << 1;
	else cout << 0;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C') {
		if(d[2]=='A'||d[2]=='B'||d[2]=='C') cout << 1;
		else cout << 0;}
	else if (b[2]=='F'||b[2]=='D') {
		if(d[2]=='D'||d[2]=='F') cout << 1;
		else cout << 0;	}
	else cout << 0;
	
	if(b[2]==d[2]+1||b[2]==d[2]-1) {
		if(b[2]=='C'||b[2]=='D') cout << 0;
		else cout << 1;	}
	else if (b[2]==68||b[2]==69) {
		if(d[2]=='D'||d[2]=='F') cout << 1;
		else cout << 0;	}
	else cout << 0;
	
	
	return 0;
}
