#include<bits/stdc++.h>
using namespace std;
int y(int a,int b)
{
	int s[100000],i=0,lens=0;
	while(a!=0||b!=0)
	{
	    int c=a%2,d=b%2; 
	    a/=2,b/=2;
        if(c==1 || d==1)
        {
        	s[i]=1;
    	}
    	else
    	{
    		s[i]=0;
		}
		i++;
		lens++;
    }
    int v,l=1;
    for(int i=lens-1;i>=0;i--)
    {
    	for(int j=0;j<i;j++)
        {
    	    l=l*2;
	    }
	    v+=l*s[i];
	}
	return v;
}
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m,maxn=-1,a[200000],k,sum,zb=0;
	cin>>n>>m;
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]>maxn)
			{
				maxn=a[i];
			}
		}
		cout<<maxn;
	}
	else if(m==2)
	{
		cin>>a[0];
		for(int i=1;i<n;i++)
		{
			cin>>a[i];
			k=y(a[i-1],a[i]);
			if(k>maxn)
			{
				maxn=k;
			}
		}
		cout<<k;
	}
	else
	{
		for(int i=0;i<n-3;i++)
		{
			cin>>a[i];
	    }
	    for(int j=1;j<=m;j++)
		{
			for(int i=0;i<n;i++)
		    {
		    	sum+=y(a[zb],a[zb+1]);
		    	zb++;
		    }
		    if(sum>maxn)
		    {
		    	maxn=sum;
			}
	    cout<<sum;
	    }
	}
	return 0;
}
