//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	string ans="";
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		ans+="1";
		if(b[0]+b[1]==d[0]+d[1])
		{
			ans+="1";
			if(b[2]=='D' || d[2]=='D')
		    {
		    	if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))
		        {
		        	ans+="11";
		        }
		        else
		        {
		            ans+="00";
		        }
		    }
		    else
		    {
		    	if(b[2]=='B'||d[2]=='B')
		    	{
		        	ans+="11";
		        }
		        else
				{
		            ans+="10";
				}
			}
		} 
		else
		{
	        ans+="000";
	    }
	}
	else
	{
	    ans+="0000";
	}
	cout<<ans;
	return 0;
 }
