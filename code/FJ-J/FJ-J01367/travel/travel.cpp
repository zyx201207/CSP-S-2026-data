#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,r1,x2,r2;
	cin>>x1>>x2>>r1>>r2;
	if(x1==r1)
	{
		cout<<1;
	}else
	{
		cout<<0;
	}
	int lie1=(x2[0]-'0')*10+(x2[1]-'0'),lie2=(r2[0]-'0')*10+(r2[1]-'0');
	if(lie1==lie2&&x1==r1)
	{
		cout<<1;
	}else
	{
		cout<<0;
	}
	bool xx,rr;
	if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C')
	{
		xx=true;
	}else
	{
		xx=false;
	}
	if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C')
	{
		rr=true;
	}else
	{
		rr=false;
	}
	if(xx==rr&&lie1==lie2&&x1==r1)
	{
		cout<<1;
	}else
	{
		cout<<0;
	}
	char xa=x2[2],ra=r2[2];
	bool flag=true;
	if((xa=='C'&&ra=='D')||(xa=='D'&&ra=='C'))
	{
		flag=false;
	}
	if(abs(xa-ra)==1&&flag&&xx==rr&&lie1==lie2&&x1==r1)
	{
		cout<<1;
	}else
	{
		cout<<0;
	}
	return 0;
}//it's easy to AC and I will AK the match
