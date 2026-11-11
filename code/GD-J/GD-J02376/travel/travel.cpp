#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else { cout<<0<<0<<0<<0;return 0;}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	else cout<<0;
	int fl=0;
	if(b[0]==d[0]&&b[1]==d[1]){
		if(b[2]=='A'){
			if(d[2]=='B'||d[2]=='C') fl=1;
		}
		if(b[2]=='B'){
			if(d[2]=='A'||d[2]=='C') fl=1;
		}
		if(b[2]=='C'){
			if(d[2]=='B'||d[2]=='A') fl=1;
		}
		if(b[2]=='D'){
			if(d[2]=='F') fl=1;
		}
		if(b[2]=='F'){
			if(d[2]=='D') fl=1;
		}
	}
	if(fl==1) cout<<1;
	else cout<<0;
	int hl=0;
	if(b[0]==d[0]&&b[1]==d[1]){
		if(b[2]=='A'){
			if(d[2]=='B') hl=1;
		}
		if(b[2]=='B'){
			if(d[2]=='A'||d[2]=='C') hl=1;
		}
		if(b[2]=='C'){
			if(d[2]=='B') hl=1;
		}
		if(b[2]=='D'){
			if(d[2]=='F') hl=1;
		}
		if(b[2]=='F'){
			if(d[2]=='D') hl=1;
		}
	}
	if(hl==1) cout<<1;
	else cout<<0;
	return 0;
} 
