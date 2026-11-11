#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int C1,C2;
	string S1,S2;
    cin>>C1>>S1>>C2>>S2;
    if(C1!=C2)
    {
    	cout<<"0000";
    }
    else
    {
    	cout<<1;
    	if(S1[0]==S2[0]&&S1[1]==S2[1])
    	{
    		cout<<1;
    		if(S1[2]=='A')
    		{
    			if(S2[2]=='B')
    			{
    				cout<<"11";
    			}
    			else if(S2[2]=='C')
    			{
    				cout<<"10";
    			}
    			else if(S2[2]=='D'||S2[2]=='F')
    			{
    				cout<<"00";
    			}
    		}
    		else if(S1[2]=='B')
    		{
    			if(S2[2]=='A')
    			{
    				cout<<"11";
    			}
    			else if(S2[2]=='C')
    			{
    				cout<<"11";
    			}
    			else if(S2[2]=='D'||S2[2]=='F')
    			{
    				cout<<"00";
    			}
    		}
    		else if(S1[2]=='C')
    		{
    			if(S2[2]=='B')
    			{
    				cout<<"11";
    			}
    			else if(S2[2]=='A')
    			{
    				cout<<"10";
    			}
    			else if(S2[2]=='D'||S2[2]=='F')
    			{
    				cout<<"00";
    			}
    		}
    		else if(S1[2]=='F')
    		{
    			if(S2[2]=='D')
    			{
    				cout<<"11";
    			}
    			else if(S2[2]=='A'||S2[2]=='B'||S2[2]=='C')
    			{
    				cout<<"00";
    			}
    		}
    		else if(S1[2]=='D')
    		{
    			if(S2[2]=='F')
    			{
    				cout<<"11";
    			}
    			else if(S2[2]=='A'||S2[2]=='B'||S2[2]=='C')
    			{
    				cout<<"00";
    			}
    		}
    	}
	    else
	    {
	   		cout<<"000";
	    }
	}
return 0;
}
