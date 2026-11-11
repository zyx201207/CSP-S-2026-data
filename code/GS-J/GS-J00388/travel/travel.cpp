#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	string  q="C";
	cin>>cr>>sr>>cx>>sx;
	int a,b,c,d;
	a=0;
	b=0;
	c=0;
	d=0;
	if(cr==cx)
	{
		a=1;
		if(sr[0]==sx[0]&&sr[1]==sx[1])
	    {
		    b=1;
	    }
	}
	if(sr[2]<=q[0]&&b==1)
	{
	    if(sx[2]<=q[0])
		{
			c=1;
		}
	}
	else if(sx[2]>q[0])
	{
		c=1;
	}
	if(c==1)
	{
		if(sr[2]+1==sx[2]||sr[2]-1==sx[2])
		{
			d=1;
		}
	}
	cout<<a<<b<<c<<d<<endl;
	
	return 0;
} 
