#include <bits/stdc++.h> 
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		int maxn = 0;
		for(int i = 1;i<=n;i++)
		{
			if(a[i]>maxn) maxn = a[i];
		}
		cout<<maxn;
	}
	else if(m==n)
	{
		int sum = a[1];
		for(int i = 2;i<=m;i++)
		{
			sum = sum&a[i];
		}
		cout<<sum;
	}
	else if(m==n-1)
	{
		int sum = 111111111;
		for(int i = 1;i<+n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if(j==i) continue;
				sum = sum&a[j];
			}
		}
		cout<<sum;
	}
	return 0;
}
