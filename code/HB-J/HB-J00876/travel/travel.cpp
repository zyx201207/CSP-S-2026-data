#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='D'||b[2]=='E'){
		if(d[2]=='E'||d[2]=='D') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		if(d[2]!='E'&&d[2]!='D') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	if(b[2]=='A'){
		if(d[2]=='B') cout<<1;
		else cout<<0;
	}
	else if(b[2]=='B'){
		if(d[2]=='A'||d[2]=='C') cout<<1;
		else cout<<0;
	}
	else if(b[2]=='C'){
		if(d[2]=='B') cout<<1;
		else cout<<0;
	}
	else{
		if(d[2]=='D'||d[2]=='E') cout<<1;
		else cout<<0;
	}
	return 0;
}
