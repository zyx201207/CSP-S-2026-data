#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if (m==1)
	{
		int maxn=INT_MIN;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if (m==2)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int maxn=INT_MIN;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				int un=a[i]&a[j];
				maxn=max(maxn,un);
			}
		} 
		cout<<maxn;
		return 0;
	}
	if (m==n)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int sum=a[1];
		for (int i=2;i<=n;i++)
		{
			sum=sum&a[i]; 
		}
		cout<<sum;
		return 0;
	}
	if (m==n-1)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int maxn=INT_MIN;
		for (int i=1;i<=n;i++)
		{
			int ans=0;
			for (int j=1;j<=n;j++)
			{
				if (j!=i)
				{
					ans=ans&a[j];
				}
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
		return 0;
	}
	cout<<0;
	return 0;
}
