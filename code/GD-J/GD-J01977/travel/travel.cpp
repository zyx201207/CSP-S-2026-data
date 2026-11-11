#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a=false,b=false,c=false,d=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		a=false;
		b=a;
		c=b;
		d=c;
	}
	else 
	{
		a=true; 
		if(s1[1]==s2[1])b=true;
		if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))c=true;
		if(c==false)d=false;
		else
		{
			if(s1[2]=='F'||s1[2]=='D')d=true;
			else 
			{
				if(abs((int)s1[2]-(int)s2[2])==1)d=true;
				else d=false;
			}
		} 
	}
	cout<<a<<b<<c<<d;
} 
