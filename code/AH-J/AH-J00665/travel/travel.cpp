#include<bits/stdc++.h>
using namespace std;
string at,bt,as,bs;
char a,b;
int an,bn;
bool f;
	char ap,bp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>at>>as>>bt>>bs;
	if(at==bt){
		cout<<1;
	}
	else {cout<<0<<0<<0<<0;return 0;}
	a=as[2];
	b=bs[2];
	an=(as[0]-48)*10+(as[1]-48);
	bn=(bs[0]-48)*10+(bs[1]-48);
	if(an==bn) cout<<1;
	else {cout<<0<<0<<0;return 0;}
	if(a=='A'||a=='B'||a=='C') {ap='A';}
	else if(a=='E'||a=='F') {ap='B';}
	if(b=='A'||b=='B'||b=='C') {bp='A';}
	else if(b=='E'||b=='F') {bp='B';}
	if(ap==bp) f=1;
	else f=0;
	cout<<f;
	if(f==0) {cout<<0;return 0;}
	bool fl=(a+1==b)||(a-1==b);
	cout<<fl;
}
