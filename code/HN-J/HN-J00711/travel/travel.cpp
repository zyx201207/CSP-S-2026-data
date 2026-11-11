#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc)cout<<1;
	else cout<<0;
	
	if(rc==xc&&rs[0]==xs[0]&&rs[1]==xs[1])cout<<1;
	else cout<<0;
	
	int i=0;
	if(rs[2]=='D'||rs[2]=='F')i++;
	if(xs[2]=='D'||xs[2]=='F')i++;
	if(rc==xc&&rs[0]==xs[0]&&rs[1]==xs[1]&&(i==2||i==0))cout<<1;
	else cout<<0;
	
	int a=0;
	if(rc==xc&&rs[0]==xs[0]&&rs[1]==xs[1]&&(i==2||i==0)){
		int r=0,x=0;
		if(rs[2]=='A')r=1; if(xs[2]=='A')x=1;
		if(rs[2]=='B')r=2; if(xs[2]=='B')x=2;
		if(rs[2]=='C')r=3; if(xs[2]=='C')x=3;
		if(rs[2]=='D')r=4; if(xs[2]=='D')x=4;
		if(rs[2]=='F')r=5; if(xs[2]=='F')x=5;
		if(abs(r-x)==1)a++;
	}
	cout<<a; 
	return 0;
} 
