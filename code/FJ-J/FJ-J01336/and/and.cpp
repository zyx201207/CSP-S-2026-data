#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[1];
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans & a[i];
		}
		cout<<ans;
	}
	else if(m==2)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
				int t=(a[i] & a[j]);
				
				//cout<<t<<endl;
				maxx=max(maxx,t);
			}
			}
		}
		cout<<maxx;
	}
	else if(m==n-1)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
		{
			int ans=0;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					ans=ans & a[j];
				}
				
			}
			maxx=max(maxx,ans);
		}
		cout<<maxx;
	}
	else
	{
		sort(a+1,a+1+n);
		int ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans =ans & a[i];
		}
		cout<<ans;
	}
	return 0;
}
