#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005],maxn=-1,a1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxn=max(maxn,a[i]);	
		}
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
	}
	else if(m==3)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i+1;j<=n-1;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					a1=(a[i]&a[j]);
					maxn=max(maxn,(a[k]&a1));
				}
			}
		}
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			a1=a1&a[i]; 
		}
		maxn=a1;
	}
	cout<<maxn;
	return 0;
}
