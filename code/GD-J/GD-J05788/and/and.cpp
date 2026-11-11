#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		int sum=a[1];
		for(int i = 2;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==1)
	{
		int max = 0;
		for(int i = 1;i<=n;i++)
		{
			if(max<a[i])
			{
				max=a[i];
			}
		}
		cout<<max;
		return 0;
	}
	if(m==2)
	{
		int sum=0;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if((a[i]&a[j])>sum)
				{
					sum=a[i]&a[j];
				}
			}
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
