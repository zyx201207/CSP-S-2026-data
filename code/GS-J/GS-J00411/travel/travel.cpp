#include<bits/stdc++.h>
using namespace std;
string a[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
int x;
string  n,s;
char m[3];
char d[3];
cin>>n>>m[0]>>m[1]>>m[2]>>s>>d[0]>>d[1]>>d[2];
for(int i=0;i<x;i++)
{
	if(n==s)
	{
		a[0]='1';
	}
	else
	{
		a[0]='0';
	}
   	if(m[2]==d[2]||m[0]!=d[0]||m[1]!=m[1])
   	{
   		a[1]='0';
	   }
	else
	{
		a[1]='1';
	}
    if(m[2]=='A'&&d[2]=='B')
    {
       a[2]='1';
       a[3]='1';
	}else if(m[2]=='B'&&d[2]=='C')
	{
		a[2]='1';
		a[3]='1';
	}else if(m[2]=='D'&&d[2]=='F')
	{
		a[2]='1';
		a[3]='1';
	}else if(m[2]=='C'&&d[2]=='A')
	{
	    a[2]='1';
	    a[3]='0';
	}else if(m[2]=='C'&&d[2]=='D')
	{
		a[2]='0';
		a[3]='0';
	}else if(m[2]==d[2])
	{
		a[2]='0';
		a[3]='0';
	}else if(m[1]!=d[1])
	{
		a[1]='0';
		a[2]='0';
		a[3]='0';
	}
}
cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
