#include<bits/stdc++.h>
using namespace std;
int c,t,a[200000],m[200000],x=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int n,d;
	for(int i=1;i<=t;i++)
	{
		x=0;
		cin>>n>>d;
		for(int j=0;j<n;j++)
	    {
	    	cin>>a[j];
	    }
	    
		for(int j=0;j<n;j++)
	    {
	    	for(int h=j+1;h<n;h++)
	        {
	        	if(a[h]-a[j]>=d)
	        	{
	        		for(int k=j;k<n;k++)
	                {
	                	for(int l=k+1;l<n;l++)
	                    {
	                    	if(a[h]-a[j]-a[l]+a[k]<d)
	                    	{
	                    		m[j]++;
	                    	}
	                    	if(m[j]==2)
	    					{
	    						x++;
	    						
	    		
	    					}
	                    }
	                	
	                }
	        	}
	        	
	        }
	    	
	    }
	    if(x%2==1)
	    {
	    	x++;
	    }
	    else
	    {
	    	x--;
	    }
		cout<<x<<endl;
    }
    return 0;	
}
