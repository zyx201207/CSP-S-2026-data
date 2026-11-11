#include <bits/stdc++.h>
using namespace std;
int n,m,a[10001],sum;
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
	if(m==1)
	{
		cout<<a[n];
	}
	if(m==n-1)
	{
		for(int i=2;i<=n;i++)
		{
			sum=a[i] and a[i+1];
		}
	}
	return 0;
}

