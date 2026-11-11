#include <bits/stdc++.h> 
using namespace std;
int a[200005];
int main()
{
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
		for(int i = 2;i<=n;i++)
		{
			sum = sum&a[i];
		}
		cout<<sum;
	}
	else if(m==n-1)
	{
		int maxn = 0;
		for(int i = 1;i<=n;i++)
		{
			int sum = a[1];
			for(int j = 1;j<=n;j++)
			{
				if(j==i) continue;
				sum = sum&a[j];
			}
			if(sum>maxn) maxn = sum;
		}
		cout<<maxn;
	}
	return 0;
}
