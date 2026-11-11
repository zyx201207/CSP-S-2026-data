#include<bits/stdc++.h>
using namespace std;


bool a,aa,aaa,aaaa;

int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

string a1,a2,b1,b2;

cin>>a1>>a2>>b1>>b2;
if(a1==b1)
{
	a=1;
}
if((a2[0]==b2[0])&&(a2[1]==b2[1]))
{
	aa=a;
}

if(((a2[2]<='C')&&(b2[2]<='C')) || ((a2[2]>'C')&&(b2[2]>'C')))
{
	aaa=a*aa;
}

if(abs(a2[2]-b2[2])==1)
{
	aaaa=a*aa*aaa;
}
cout<<a<<aa<<aaa<<aaaa;
return 0;	
}
