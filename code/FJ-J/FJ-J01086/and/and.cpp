#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	cin>>n>>m;
	int a[n+10];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m=1)
	{
		cout<<a[n];
	}
	else if(m=2)
	{
		int c=(n-1)*n/2;
	    int b[c+10];
		int k=1;
		for(int i=1;i<n;i++)
	    {
		    for(int j=i+1;j<=n;j++)
		    {
		    	b[k]=a[i]&a[j];
		    	k++;
		    }
	    }
	    sort(b+1,b+c+1);
	    cout<<b[c];
	}
	else if(m=3)
	{
		int c=(n-1)*n/2;
	    int b[c+10];
		int k=1;
		for(int l=1;l<n-1;l++)
		{
			for(int i=l+1;i<n;i++)
	        {
		        for(int j=i+1;j<=n;j++)
		        {
		    	    b[k]=a[l]&a[i]&a[j];
		    	    k++;
		        }
	        }
		}
	    sort(b+1,b+c+1);
	    cout<<b[c];
	}
	else if(n==m)
	{
		int ans;
		for(int i=1;i<n;i++)
		{
			ans=a[i]&a[i+1];
		}
	}
	return 0;
}
