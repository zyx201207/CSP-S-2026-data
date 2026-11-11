#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(rs.substr(0,2)==xs.substr(0,2))cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((rs[2]=='A'||rs[2]=='B'||rs[2]=='C')&&(xs[2]=='A'||xs[2]=='B'||xs[2]=='C')||
		(rs[2]=='D'||rs[2]=='F')&&(xs[2]=='D'||xs[2]=='F')
	)cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((rs[2]=='A'&&xs[2]=='B')||
		(xs[2]=='A'&&rs[2]=='B')||
		(rs[2]=='B'&&xs[2]=='C')||
		(xs[2]=='B'&&rs[2]=='C')||
		(rs[2]=='D'&&xs[2]=='F')||
		(xs[2]=='D'&&rs[2]=='F')
	)cout<<1;
	else cout<<0;
	return 0;
} 
