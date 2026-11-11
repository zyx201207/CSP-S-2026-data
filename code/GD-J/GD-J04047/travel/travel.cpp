#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int n,x,xx;
bool y,yy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	x=(b[0]-'0')*10+b[1]-'0';
	xx=(d[0]-'0')*10+d[1]-'0';
	if(b[2]=='A'||b[2]=='B'||b[2]=='C')y=1;
	if(d[2]=='A'||d[2]=='B'||d[2]=='C')yy=1;
	bool l=0;
	if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))l=1;
	else if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]==d[2]-1||d[2]==b[2]-1||b[2]==d[2]+1||d[2]==b[2]+1))l=1;
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&x==xx)cout<<1;
	else cout<<0;
	if(a==c&&x==xx&&y==yy)cout<<1;
	else cout<<0;
	if(a==c&&x==xx&&y==yy&&l)cout<<1;
	else cout<<0;
	return 0;
} 
