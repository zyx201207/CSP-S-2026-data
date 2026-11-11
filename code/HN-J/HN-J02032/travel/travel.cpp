#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	char q[6],w[6];
	int e,r;
	for(int i=1;i<=6;i++)
	{
		q[i]=getchar();
	}
	getchar();
	for(int u=1;u<=6;u++)
	{
		w[u]=getchar();
	}
	e=q[6];
	r=w[6];
	if(q[1]==w[1]&&q[2]==w[2])
	  {
	    cout<<"1";
	    if(q[4]==w[4]&&q[5]==q[5])
	    {
	    	cout<<"1";
	    	if(e<=67&&r<=67)
	    	{
	    		cout<<"1";
	    		if(e-r==1||r-e==1)
	    			cout<<"1"; 
				else
				  cout<<"0";
			}
			else
			{
				if(e>67&&r>67)
				{
					cout<<"1";
					if(e-r==1||r-e==1)
	    			  cout<<"1"; 
				    else
				      cout<<"0";
				 } 
				 else
				   cout<<"00";
			 
		    }
	  }
	  else
		  cout<<"000";
     }
	else
	  cout<<"0000";
		
	return 0;
	 
}
