#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string r1,r2;
string x1,x2;
cin>>r1>>r2>>x1>>x2;
int a=0,b=0,c=0,d=0;
if(r1==x1)
{
	a=1;
	if(x2[0]==r2[0]&&x2[1]==r2[1])
	{
		b=1;
		if(((x2[2]=='A'||x2[2]=='B'||x2[2]=='C')&&(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'))||((x2[2]=='D'||x2[2]=='F')&&(r2[2]=='D'||r2[2]=='F')))
       {
       	   c=1;
       	  if((x2[2]=='A'&&r2[2]=='B')||(x2[2]=='B'&&r2[2]=='A')||(x2[2]=='B'&&r2[2]=='C')||(x2[2]=='C'&&r2[2]=='B')||(x2[2]=='D'&&r2[2]=='F')||(x2[2]=='F'&&r2[2]=='D'))
          {
          	  d=1;
          }
       }
	}
}
cout<<a<<b<<c<<d;
	return 0;
}
