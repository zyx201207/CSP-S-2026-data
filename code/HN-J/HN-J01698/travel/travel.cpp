#include<iostream>
using namespace std;
string a,b,c,d;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	x=(b[0]-'0')*10+b[1]-'0';
	y=(d[0]-'0')*10+d[1]-'0';
	if(a==c) cout<<1;
	else cout<<0;
	if(x==y) cout<<1;
	else cout<<0;
	if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'
	||b[2]=='A'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'
	||b[2]=='C'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'
	||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D') cout<<1;
	else cout<<0;
	if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'
	||b[2]=='C'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'
	||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D') cout<<1;
	else cout<<0;
	return 0;
} 
