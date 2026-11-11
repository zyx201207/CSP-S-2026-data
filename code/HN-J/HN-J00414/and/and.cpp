#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,c=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n||m==n-1)
	{
		for(long long i=1;i<=n;i++)
		{
			if(a[i]<a[c])
			{
				c=i;
			}
		}
		m++;
		if(m>=n)
		{
			cout<<a[c];
			return 0;
		}
		else
		{
			a[c]=0;
			c=1;
		}
	}
	while(m>=0)
	{
		for(long long i=1;i<=n;i++)
		{
			if(a[i]>a[c])
			{
				c=i;
			}
		}
		m--;
		if(m==0)
		{
			cout<<a[c];
			return 0;
		}
		else
		{
			a[c]=0;
			c=1;
		}
	}
	return 0;
}
