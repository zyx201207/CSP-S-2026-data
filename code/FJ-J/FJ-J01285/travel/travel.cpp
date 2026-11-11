#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rcar,rs,xcar,xs;
	cin>>rcar>>rs>>xcar>>xs;
	int t1=1,t2=1,t3=1,t4=1;
	for(int i=0;i<rcar.size();i++)
	{
		if(rcar[i]!=xcar[i])
		{
			t1=0;
			t2=0;
			t3=0;
			t4=0;
		}
	}
	for(int i=0;i<rs.size()-1;i++)
	{
		if(rs[i]!=xs[i])
		{
			t2=0;
			t3=0;
			t4=0;
		}
	}
    if(rs[2]=='A'||rs[2]=='B'||rs[2]=='C')
    {
    	if(xs[2]=='D'||xs[2]=='F')
    	{
    		t3=0;
    		t4=0;
		}
	}
	else
	{
		if(xs[2]=='A'||xs[2]=='B'||xs[2]=='C')
		{
			t3=0;
			t4=0;
		}
	}
	if(rs[2]=='A')
	{
		if(xs[2]!='B')t4=0;
	}
	if(rs[2]=='B')
	{
		if(xs[2]!='A'&&xs[2]!='C')t4=0;
	}
	if(rs[2]=='C')
	{
		if(xs[2]!='B')t4=0;
	}
	if(rs[2]=='D')
	{
		if(xs[2]!='F')t4=0;
	}
	if(rs[2]=='F')
	{
		if(xs[2]!='D')t4=0;
	}
	cout<<t1<<t2<<t3<<t4;
	return 0;
}
