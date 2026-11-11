#include<bits/stdc++.h>
using namespace std;
int a,a1,p,pp,ppp;
string b,b1,x,xx;
char y,yy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>a1>>b1;
	x=b[0]+b[1];
	xx=b1[0]+b1[1];
	y=b[2];
	yy=b1[2];
	if(a==a1)
	{
		cout<<1;
		ppp=1;
	}
	else
	{
		cout<<0;
	}
	if(ppp==1&&x==xx)
	{
		cout<<1;
		pp=1;
	}
	else
	{
		cout<<0;
	}
	if(ppp==1&&pp==1&&y<='C'&&yy<='C'||ppp==1&&pp==1&&y>='D'&&yy>='D')
	{
		cout<<1;
		p=1;
	}
	else
	{
		cout<<0;
	}
	if(p==1&&y+1==yy||p==1&&y-1==yy)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
