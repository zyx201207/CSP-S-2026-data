#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,c2,s1,s2,daan="0000";
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
	{
	    daan[0]='1';
	    if(s1[0]==s2[0]&&s1[1]==s2[1])
	    {
	    	daan[1]='1';
	    	if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')
	    	{
	    		daan[2]='1';
	    		if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
	    		{
	    			daan[3]='1';
	    			cout<<daan;
	    			return 0;
				}
			}
			if(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='D'&&s2[2]>='F')
			{
				daan[2]='1';
				daan[3]='1';
				cout<<daan;
				return 0;
			}
		}
	    
    }
    cout<<daan;
    return 0;
}
