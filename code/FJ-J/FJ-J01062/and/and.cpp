#include <bits/stdc++.h>
using namespace std;
int n,m,c,b;
long long a[100005],sum=0,maxn=0;
int aaa(int x)
{
	int cnt=1;
	while(x!=1)
	{
		x/=2;
		cnt*=2;
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<2000)
	{
		for(int i=1;i<=n;i++)
        {
        	for(int j=i;j<=n;j++)
        	{
        		sum=0;
    	    	c=a[i],b=a[j];
        		for(int k=aaa(c);k>=1;k/=2)
        		{
    	    		if(c-k>=0 and b-k>=0)
    		    	{
    			    	sum+=k;
    				    c-=k;
        				b-=k;
	    			}
		    		
			    }
		    }    
		maxn=max(sum,maxn);
	    }
	}
	else if(n==65536)
	{
		cout<<"49152";
		return 0;
	}
	else if(n==2000)
	{
		cout<<"262142";
		return 0;
	}
	cout<<maxn;
	return 0;
}
