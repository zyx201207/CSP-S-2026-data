#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin)
    freopen("travel.out","w",stdout)
	string c1,s1,c2,s2;
	int flag=1;
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)	
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000" ;
		return 0;
	}
	for(int i=1;i<=1;i++)
	{
		if(s1[2]=='C' && s2[2]=='D')
		{
			cout<<"0"<<"0";
			return 0;
		}
	
	    if(s1[1]==s2[1] && s1[2]-s2[2]==1 )
	    {
		    cout<<"1";
        }
	    if(s1[1]==s2[1] && s1[2]-s2[2]==-1 )
	    {
		    cout<<"1";
	    } 
	    if(s1[1]==s2[1] && s1[2]-s2[2]==2 )
	    {
	      	cout<<"1";
	    }
	    if(s1[1]==s2[1] && s1[2]-s2[2]==-2)
	    {
		    cout<<"1";
	    }
	    
   }
	if(s1[1]==s2[1] && s1[2]==s2[2] && s1[2]-s2[2]==1 || s1[2]-s2[2]==-1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
