#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
struct op
{
	int x;
	long long y;
}  f,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	f.x=1,r.x=n,f.y=a[1],r.y=a[n];
	long long ans=0;
	while(f.x<=r.x)
	{
		if(b[f.x]!=b[r.x])
		{
			ans=ans+min(f.y,r.y);
		}
		if(f.y>r.y)
		{
			r.x--;
			f.y-=r.y;
			r.y=a[r.x];
		}
		else
		{
			if(r.y>f.y)
	    	{
	    		f.x++;
	      		r.y-=f.y;
	       		f.y=a[f.x];
	    	}
	    	else
	    	{
	    		if(r.y==f.y)
         		{
        	     	r.x--;
        			f.x++;
         			f.y=a[f.x];
         			r.y=a[r.x];
	        	}
			}
    		
		}
		
	}
	cout<<ans;
	return 0;
}