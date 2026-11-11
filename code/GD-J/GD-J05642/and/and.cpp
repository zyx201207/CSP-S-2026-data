#include <iostream>
#include <algorithm>
using namespace std;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		 } 
		 cout<<maxn;
		 return 0;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		} 
		cout<<ans;
		return 0;
	}
	else if(m==2)
	{
		int maxn=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	else
	{
		int maxn=0;
		do{
			int ans=a[1];
			for(int i=2;i<=m;i++)
			{
				ans=ans&a[i];
			}
			maxn=max(maxn,ans);
		}while (next_permutation(a+1,a+n+1));
		cout<<maxn;
		return 0;
	}
	return 0;
}
