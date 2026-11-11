#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	bool che=true,x=true,ce=true;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		che=false;
	}
    if(che)
    {
    	if(s1[0]==s2[0]&&s1[1]==s2[1])
    	{
    		cout<<"1";
		}
		else
		{
			cout<<"000";
			x=false;
		}
		if(x)
		{
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')&&x==true)
		    {
			    cout<<"1";
			}
			else
			{
				cout<<"00";
				ce=false;
			}
			if(ce)
			{
				if((s1[2]+1==s2[2])||(s1[2]-1==s2[2])||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	        	{
		        	cout<<"1";
	        	}
	        	else
	        	{
		        	cout<<"0";
	        	}
			}
		
		}
	}
		

	return 0;
}
