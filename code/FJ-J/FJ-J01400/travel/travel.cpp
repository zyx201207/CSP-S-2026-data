#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a!=x)
	{
		cout<<'0'<<'0'<<'0'<<'0';
		return 0;
	}
	int t=1;
	for(int i=0;i<2;i++)
	{
	    if(b[i]!=y[i])
	    {
	    	t=0;
	    	break;
		}
	}
    if(t==0)
	{
		cout<<'1'<<'0'<<'0'<<'0';
		return 0;
	}
	int ans=b[2]-'0';
	int sum=y[2]-'0';
	if(b[2]<='C' && y[2]<='C')
	{
        if(b[2]>y[2])
		{
		    if(ans-sum==1)
		    {
			    cout<<'1'<<'1'<<'1'<<'1';
		    }
		    else
		    {
			    cout<<'1'<<'1'<<'1'<<'0';
		    }	
		}
		else
		{
		    if(sum-ans==1)
		    {
			    cout<<'1'<<'1'<<'1'<<'1';
		    }
		    else
		    {
			    cout<<'1'<<'1'<<'1'<<'0';
		    }	
		}
	}
	else if(b[2]>='D' && y[2]>='D')
	{
		if(b[2]<y[2])
		{
		    if(sum-ans==1)
		    {
			    cout<<'1'<<'1'<<'1'<<'1';
		    }
		    else
		    {
			    cout<<'1'<<'1'<<'1'<<'0';
		    }	
		}
		else
		{
		    if(ans-sum==1)
		    {
			    cout<<'1'<<'1'<<'1'<<'1';
		    }
		    else
		    {
			    cout<<'1'<<'1'<<'1'<<'0';
		    }	
		}
	}
	else
	{
		cout<<'1'<<'1'<<'0'<<'0';
	}
	return 0;
}
