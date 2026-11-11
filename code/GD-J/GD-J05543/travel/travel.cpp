#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c)
    {
    	cout<<1;
    	if(b[1]=d[1])
    	{
    		if(b[2]=d[2])
    		{
    			int n=0;
    			cout<<1;
    			for(int i=2;i<4;i++)
    			{
				    
    			    if(b[i]>='A'&&b[i]<='C')
    			    {
    			    	if(d[i]>='A'&&d[i]<='C')
    			    	{
    			    		cout<<"1";
    			    		n=1;
						}
				    } 

			    }
			    if(n!=1)
			    {
			    	cout<<"00";
			    	return 0;
				}
		    }
		    else
		    {
		        cout<<"000";
		        return 0;
	        }
	    }
	    else
		{
		    cout<<"000";
		    return 0;
	    }
	}
	else
	{
		cout<<"0000";
		return 0;
	}
    return 0;
} 
