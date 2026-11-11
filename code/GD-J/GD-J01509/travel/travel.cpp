#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,x=0,y=0,z=0,i=0;
	char c,d,e,f,g,h;
	cin>>a>>c>>d>>e>>b>>f>>g>>h;
	
	if(a==b)
	{
		cout<<'1';
	}else
	{
		cout<<'0';
		i++;
	}
	
	if(i>0)
	{
		cout<<'0';
		y++;
	}else
	{
		if(c==f&&d==g)
    	{
    		cout<<'1';
    		z++;
    	}else
    	{
    		cout<<'0';
    		y++;
    	}
	}
	
	if(z==0)
	{
		cout<<'0';
		y=1;
    }else
    {
    	if(e=='D'||h=='D')
    	{
    		if(h=='F'||e=='F')
	    	{
	    		cout<<'1';
	    		x=1;
	    	}else
	    	{
	    		cout<<'0';
	    		y++;
	    	}
    	}else if(h=='F'||e=='F')
	    {
	    	if(e=='D'||h=='D')
	    	{
	    		cout<<'1';
	    		x=1;
	    	}else
	    	{
		    	cout<<'0';
	    		y++;
	    	}
	    }else
	    {
		    cout<<'1';
    	}
	}
	
	if(x==1)
	{
		cout<<'1';
	}else if(y==1)
	{
		cout<<'0';
	}else if(h=='A'&&e=='C')
	{
		cout<<'0';
	}else if(e=='A'&&h=='C')
	{
		cout<<'0';
	}else
	{
		cout<<'1';
	}
	return 0;
}
