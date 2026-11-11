#include<bits/stdc++.h>
using namespace std;
int n,p;
string cr,cx,sr,sx,r,x;
char a,b;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>cr>>sr>>cx>>sx;
	r=sr.substr(0,2);
	x=sx.substr(0,2);
	a=sr[2];b=sx[2];
	
	if(cr==cx)cout<<1;
	else {
		cout<<0<<0<<0<<0;
		exit(0);
	}
	
	if(r==x)cout<<1;
	else {
		cout<<0<<0<<0;
		exit(0);
	}
	
	if(a>='D'&&b<='C'){
		cout<<0;
	}
	else if(a<='C'&&b>='D'){
		cout<<0;
	}
	else {
		cout<<1;
		p=1;
	}
	
	if(((int)a-(int)b==1)||((int)a-(int)b==-1)){
		if(p==1)cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}