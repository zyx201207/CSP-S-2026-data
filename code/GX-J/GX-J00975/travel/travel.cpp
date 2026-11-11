#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
string a,b,l,r;
int a1,b1,c,d;
char k,m;
bool f=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a>>b1>>b;
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	if(a1==b1)
	{
		cout<<"1";
	}
	l=a[0]+a[1];
	r=b[0]+b[1];
	if(l==r)
	{
		cout<<"1";
	}
	else if(l!=r)
	{
		cout<<"0";
		f=1;
	}
	k=a[2];
	m=b[2];
	c=int(k)-64;
	d=int(m)-64;
	if(f==1)
	{
		cout<<"00";
		return 0;
	}
	else if((c<=3&&d<=3)||(c>3&&d>3))
	{
		cout<<"1";
	}
	if((c<=3&&d>3)||(c>3&&d<=3))
	{
		cout<<"0";
	}
	if((c<=3 && d<=3 && abs(c-d)==1)||(c>3 && d>3 && abs(c-d)==1))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
