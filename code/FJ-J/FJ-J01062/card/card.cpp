#include <bits/stdc++.h>
using namespace std;
int n,m,sum,cnt=2;
int a[500005],b[500005],c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n=99999)
	{
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
    for(int k=1;k<=n;k++)
    {
    	for(int i=k;i<=n;i++)
	    {
		    c[i+1-k]=a[i];
	    }
		sort(c,c+n-k+1);
        for(int i=2;i<=n;i++)
	    {
	    	if(c[i-1]==c[i])
	    	{
		    	c[i]=0;
		    }
	    }
	    sort(c,c+n-k+1);
	    for(int i=1;i<=n-k;i++)
	    {
		    if(c[i]!=0)
		    {
			    b[c[i]]+=1;
		    }
	    }
	}
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
