#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r, x, c, d;
	string a, b;
	cin>>r>>a>>x>>b;
	c = (a[0]-48)*10+(a[1]-48);
	d = (b[0]-48)*10+(b[1]-48);
	if(r == x){
		cout << 1;
	}else{
		cout << 0000;
		return 0;
	}
	if(c == d){
		cout << 1;
	}else{
		cout<<000;
		return 0;
	}
	if(((a[2]=='A'||'B'||'C' )&& (b[2]=='A'||'B'||'C')) || ((a[2]=='D'||'F' )&&(b[2]=='D'||'F'))){
		cout << 1;
	}else{
		cout << 00;
		return 0;
	}
	if((a[2]+1 == b[2]+0)||(a[2]+0 == b[2]+1)){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
