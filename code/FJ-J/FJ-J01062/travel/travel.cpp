#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[1]==s2[1] and s1[0]==s2[0])
	    {
	    	cout<<"1";
		    if(s1[2]-'A'<='C'-'A' and s2[2]-'A'<='C'-'A')
	        {
	        	cout<<"1";
	    	    if(s1[2]-'A'+1==s2[2]-'A' or s1[2]-'A'-1==s2[2]-'A')
	    	    {
	    	    	cout<<"1";
				}
				else
				{
					cout<<"0";
				}
	        }
	        else if(s1[2]-'A'>'C'-'A' and s2[2]-'A'>'C'-'A')
	        {
	        	cout<<"11";
	        }
	        else
	        {
	        	cout<<"00";
	    	}
    	}
	    else
    	{
    		cout<<"000";
	    }
	}
	else
	{
		cout<<"0000";
	}
	
	return 0;
}
