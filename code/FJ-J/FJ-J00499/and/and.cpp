#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000000],sum; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[n];
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		for(int i=n-1;i>=1;i++)
		{
			sum=(sum&a[i]);
		}
		cout<<sum;
	}
	if(m==(n-1))
	{
		for(int i=n-1;i>=2;i++)
		{
			sum=(sum&a[i]);
		}
		cout<<sum;
	}
	if(m==2)
	{
		cout<<(a[n]&a[n-1]);
	}
	return 0;
}
