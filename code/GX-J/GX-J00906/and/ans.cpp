#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],maxn=0,maxx;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n-1)
	{
		int ans=INT_MAX;
		for(int i=1;i<=n-1;i++)
		{
			ans&=a[i];
		}
		maxx=ans;
		ans=INT_MAX;
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		maxx=max(maxx,ans);
	}
	else if(m==n)
	{
		int ans=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
	}
	else
	{
		for(int i=0;pow(2,i)<=N;i++)
		{
			if(n==pow(2,i))
			{
				int ans=INT_MAX;
				for(int i=0;i<m;i++)
				{
					ans&=a[n-i];
				}
				cout<<ans;
				return 0;
			}
		}
		int ans=INT_MAX;
		for(int i=0;i<m;i++)
		{
			ans&=a[n-i];
		}
		cout<<ans;
	return 0;
	}
	sort(a+1,a+n+1);
	int ans=INT_MAX;
		for(int i=0;i<m;i++)
		{
			ans&=a[n-i];
		}
		cout<<ans;
	return 0;
}
