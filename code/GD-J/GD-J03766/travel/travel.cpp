#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","W",stdout);
	int x,r;
	string x1,r1;
    cin>>x>>x1>>r>>r1;  
	if(x==r)
    {
    	cout<<"1";
    	if(x1[0]==r1[0]&&x1[1]==r1[1])
    	{
    		cout<<"1";
    		if((x1[2]<='C'&&r1[2]<='C')||(x1[2]>'C'&&r1[2]>'C'))
    		{
    			cout<<"1";
    			if(x1[2]-r1[2]==1||x1[2]-r1[2]==-1)
    			    cout<<"1";
    			else
    			    cout<<"0";
			}
			else
				cout<<"00";
		}
		else
		    cout<<"000";
	}
	else
	    cout<<"0000";
	return 0;	
} 
