#include <bits/stdc++.h>
using namespace std;
int x,y;
string xc,yc,xx,yy,ans;
char a,b;
int c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xc>>xx>>yc>>yy;
	a=xx[2];
	b=yy[2];
	c=(xx[0]-'0')*10+xx[1]-'0';
	d=(yy[0]-'0')*10+yy[1]-'0';
	x=(xc[0]-'0')*10+xc[1]-'0';
	y=(yc[0]-'0')*10+yc[1]-'0';
	if(x==y) ans+='1';
	else ans+='0';
	
	if(x==y && c==d) ans+='1';
	else ans+='0';
	
	if(x==y && c==d){
		if(a>='A' && a<='C' && b>='A' && b<='C') ans+='1';
		else if(a>='D' && a<='E' && b>='D' && b<='E') ans+='1';
		else ans+='0';
	}else{
		ans+='0';
	}
	
	if((b==a+1 || b==a-1) && c==d){
		if(a=='C' && b=='D') ans+='0';
		else ans+='1';
	}else{
		ans+='0';
	}
	cout<<ans;
	return 0;
}
