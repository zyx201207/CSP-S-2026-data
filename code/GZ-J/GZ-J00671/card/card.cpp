#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,k,o=1,ttt;
	cin>>n>>k;
	vector<long long> a(n+10),x(n+10),a1(n+10),ans(n+10),a2(n+10);
	if(n==k)
	{
		for(long long i=1;i<=n;i++)
	    {
		    cin>>a[i];
		    x[a[i]]=i;
    	}
    	for(long long i=1;i<=n;i++)
	    {
		    cout<<x[i]<<" ";
    	}
    	return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		a1[i]=a[i];
	}
	for(long long p=1;p<=k;p++)
	{
		ttt=n;
		o=1;
		a2[n]={-66};
		for(long long i=p;i<=ttt;i++)
	    {
		    a1[i]=a[i];
	    }
		for(long long i=p;i<=n;i++)
		{
			for(long long j=i;j>=p;j--)
	   	    {
			    if(a[j]==a[i] && j!=i)
				{
			            for(long long y=n;y>=i;y--)
	    	            {
			                a1[y-i+j]=a1[y];
	    	            }
	    	            ttt=n-i+j;
				} 
	   		}
		}
		sort(a1.begin()+p,a1.begin()+n);
		for(long long j=n;j>=p;j--)
	    {
		    if(a1[j]==-99)
			{
			   break;
		    }
		    else
			{
			   	a2[o]=a1[j];
			   	o++;
			}
	   	}
	   	for(long long i=1;i<=o;i++)
	    {
		    ans[a2[i]]++;
	    }
	}
	cout<<ans[a[1]]-2<<" ";
	for(long long i=2;i<=k;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
 } 
