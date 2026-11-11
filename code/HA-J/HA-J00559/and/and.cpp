#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long maxx=-1;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	maxx=max(maxx,a[i]);
    }
    if(m==1)
    {
    	cout<<maxx;
    }
    else if(n==m)
    {
    	long long x=a[1];
    	for(int i=2;i<=n;i++)
    	{
    		x=x&a[i];
    	}
    	cout<<x;
    }
    else if(m==2)
    {
    	maxx=-1;
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=n;j++)
    		{
    			if(i!=j)
    			{
    				long long y=a[i]&a[j];
    				maxx=max(maxx,y);
    			}
    		}
    	}
    	cout<<maxx;
    }
    else 
    {
    	sort(a+1,a+1+n);
        long long x=a[n];
        for(int i=n-1;i>=m;i--)
        {
    	    x=x&a[i];
        }
        cout<<x;
    }
	return 0;
}
