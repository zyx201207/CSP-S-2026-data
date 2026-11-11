#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	
	if(a==c) cout << 1;
	else{
		cout <<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) {
		cout << 1;
		if(b[2]<='C'&&d[2]<='C') cout << 1;
		else if(b[2]>='D'&&b[2]>='D') cout << 1;
		else cout << 0;
	}
	else cout << 0<<0;
	if(b[0]==d[0]&&b[1]==d[1]) {
		if(int(b[2])-1==int(d[2])||int(b[2])+1==int(d[2])){
			if(b[2]=='D'&&d[2]=='C'||b[2]=='C'&&d[2]=='D') cout <<0;
				else cout << 1;
		}
		else cout <<0;
	}
	else cout << 0;
	return 0;
}
