#include<bits/stdc++.h>
using namespace std;
int c1,c2,a,b,c,d;
string s1,s2,s3,s4;
char aa,bb,cc,dd;
char x1,x2,yy1,y2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

cin>>c1>>s1>>c2>>s2;
	aa=s1[2];
	bb=s2[2];
	x1=s1[0];
	x2=s1[1];
	yy1=s2[0];
	y2=s2[1];

cc=aa-'A';
dd=bb-'A';

if(c1==c2)
{																
	a=1;	
	if(x1==yy1&&x2==y2)
{
	b=1;
	if((cc<3&&dd<3)||(cc>=3&&dd>=3))
{
	c=1;
	if(abs(cc-dd)==1)
	{
		d=1;
	}
}
}
}
cout<<a<<b<<c<<d;
	return 0;
 } 
