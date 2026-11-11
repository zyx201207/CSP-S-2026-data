#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[10010],s,q=0,w=0,t,m1=0,h;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int r=1;r<=m+1;r++)
	{
		for(int i=1;i<=n;i++)
	    {
		    for(int j=1;j<n;j++)
	        {
	    	    if(a[j]>a[j+1])
                {
	    		    s=a[j+1];
	    		    a[j+1]=a[j];
					a[j]=s; 
    		    }
        	}
    	}
    	for(int i=1;i<=n;i++)
	    {
		    q=0;
		    for(int j=1;j<=n;j++)
	        {
	    	    if(a[j]==a[1])
                {
	    		   q+=1; 
    		    }
        	}
    	    w=max(w,q);
    	}
    	a[1]+=1;
    }
    cout<<w;
	return 0;
} 
