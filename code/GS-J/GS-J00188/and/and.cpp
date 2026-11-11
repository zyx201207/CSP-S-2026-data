#include<bits/stdc++.h>
using namespace std;

long long n=0,m=0;
long long a[200010];
long long ans=0,li=0;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a,a+n);
		cout<<a[n-1];
	}
	if(m==2)
	{
	    for(int i=0;i<n;i++)
        {
    	    for(int j=i+1;j<n;j++)
    	    {  
    	    	ans=max(ans,a[i]&a[j]);
		    }
	    }
    }
    if(m==3)
	{
	    for(int i=0;i<n;i++)
        {
    	    for(int j=i+1;j<n;j++)
    	    {  
    	        for(int q=j+1;q<n;q++)
    	        {
    	        	ans=max(ans,a[i]&a[j]&a[q]);
				}
		    }
	    }
    }
    if(m==4)
	{
	    for(int i=0;i<n;i++)
        {
    	    for(int j=i+1;j<n;j++)
    	    {  
    	        for(int q=j+1;q<n;q++)
    	        {
    	        	for(int w=q+1;w<n;w++)
    	            {
    	        	    ans=max(ans,a[i]&a[j]&a[q]&a[w]);
				    }
				}
		    }
	    }
    }
    if(m==5)
	{
	    for(int i=0;i<n;i++)
        {
    	    for(int j=i+1;j<n;j++)
    	    {  
    	        for(int q=j+1;q<n;q++)
    	        {
    	        	for(int w=q+1;w<n;w++)
    	            {
    	        	    for(int e=w+1;e<n;e++)
    	                {
    	        	        ans=max(ans,a[i]&a[j]&a[q]&a[w]&a[e]);
				        }
				    }
				}
		    }
	    }
    }
    if(m==6)
	{
	    for(int i=0;i<n;i++)
        {
    	    for(int j=i+1;j<n;j++)
    	    {  
    	        for(int q=j+1;q<n;q++)
    	        {
    	        	for(int w=q+1;w<n;w++)
    	            {
    	        	    for(int e=w+1;e<n;e++)
    	                {
    	        	        for(int r=e+1;r<n;r++)
    	                    {
    	        	            ans=max(ans,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]);
				            }
				        }
				    }
				}
		    }
	    }
    }
        if(m==7)
	{
	    for(int i=0;i<n;i++)
        {
    	    for(int j=i+1;j<n;j++)
    	    {  
    	        for(int q=j+1;q<n;q++)
    	        {
    	        	for(int w=q+1;w<n;w++)
    	            {
    	        	    for(int e=w+1;e<n;e++)
    	                {
    	        	        for(int r=e+1;r<n;r++)
    	                    {
    	        	            for(int t=r+1;t<n;t++)
    	                        {
    	        	                ans=max(ans,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]);
				                }
				            }
				        }
				    }
				}
		    }
	    }
    }
            if(m==8)
	{
	    for(int i=0;i<n;i++)
        {
    	    for(int j=i+1;j<n;j++)
    	    {  
    	        for(int q=j+1;q<n;q++)
    	        {
    	        	for(int w=q+1;w<n;w++)
    	            {
    	        	    for(int e=w+1;e<n;e++)
    	                {
    	        	        for(int r=e+1;r<n;r++)
    	                    {
    	        	            for(int t=r+1;t<n;t++)
    	                        {
    	        	                for(int y=t+1;y<n;y++)
    	                            {
    	        	                    ans=max(ans,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]);
				                    }
				                }
				            }
				        }
				    }
				}
		    }
	    }
    }
                if(m==9)
	{
	    for(int i=0;i<n;i++)
        {
    	    for(int j=i+1;j<n;j++)
    	    {  
    	        for(int q=j+1;q<n;q++)
    	        {
    	        	for(int w=q+1;w<n;w++)
    	            {
    	        	    for(int e=w+1;e<n;e++)
    	                {
    	        	        for(int r=e+1;r<n;r++)
    	                    {
    	        	            for(int t=r+1;t<n;t++)
    	                        {
    	        	                for(int y=t+1;y<n;y++)
    	                            {
    	        	                    for(int u=y+1;u<n;u++)
    	                                {
    	        	                        ans=max(ans,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]);
				                        }
				                    }
				                }
				            }
				        }
				    }
				}
		    }
	    }
    }
    if(m==10)
	{
	    for(int i=0;i<n;i++)
        {
    	    for(int j=i+1;j<n;j++)
    	    {  
    	        for(int q=j+1;q<n;q++)
    	        {
    	        	for(int w=q+1;w<n;w++)
    	            {
    	        	    for(int e=w+1;e<n;e++)
    	                {
    	        	        for(int r=e+1;r<n;r++)
    	                    {
    	        	            for(int t=r+1;t<n;t++)
    	                        {
    	        	                for(int y=t+1;y<n;y++)
    	                            {
    	        	                    for(int u=y+1;u<n;u++)
    	                                {
    	        	                        for(int o=u+1;o<n;o++)
    	                                    {
    	        	                            ans=max(ans,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]);
				                            }
				                        }
				                    }
				                }
				            }
				        }
				    }
				}
		    }
	    }
    }
	cout<<ans;
	return 0;
}
