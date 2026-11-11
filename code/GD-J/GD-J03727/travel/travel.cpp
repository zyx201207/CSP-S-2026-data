#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(rs[0]==xs[0]&&rs[1]==xs[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(rs[2]>='D'&&xs[2]>='D'){
		cout<<1<<1;
	}
	else if(rs[2]<='C'&&xs[2]<='C'){
		cout<<1;
		if(rs[2]=='B'||xs[2]=='B'){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		cout<<"00";
		return 0;
	}
	return 0;
} 
