#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int maxn=INT_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	if(m==n)
	{
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}
	if(m==1)
	{
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ans=a[i]&a[j];
				if(i!=j&&ans>maxn)
				{
					maxn=ans;
				} 
			}
		}
		cout<<maxn;
	}
	if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1) ans=a[2];
			else ans=a[1];
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					ans=ans&a[j];
				}
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
	}
}
