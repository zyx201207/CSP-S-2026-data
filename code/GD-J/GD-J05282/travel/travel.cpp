#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int x,y,i,j;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)cout<<1;
	else cout<<0;
	x=(a2[0]-'0')*10+a2[1]-'0';
	y=(b2[0]-'0')*10+b2[1]-'0';
	if(a2[2]=='A')i=1;
	else if(a2[2]=='B')i=2;
	else if(a2[2]=='C')i=3;
	else if(a2[2]=='D')i=95;
	else if(a2[2]=='F')i=96;
	if(b2[2]=='A')j=1;
	else if(b2[2]=='B')j=2;
	else if(b2[2]=='C')j=3;
	else if(b2[2]=='D')j=95;
	else if(b2[2]=='F')j=96;
	if(a1==b1&&x==y)cout<<1;
	else cout<<0;
	if(a1==b1&&x==y&&abs(i-j)<3)cout<<1;
	else cout<<0;
	if(a1==b1&&x==y&&abs(i-j)==1)cout<<1;
	else cout<<0;
	return 0;
}
