#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxx=-999,x;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	
	if (m==1)
	{
		cout<<maxx;
		return 0;
	}
	
	if (m==n)
	{
		x=a[1];
		for (int i=1;i<n;i++)
		{
			x=(x&a[i-1]);
		}
		cout<<x;
		return 0;
	}
	
	sort(a,a+n);
	maxx=-999;
	for (int i=0;i<n;i++)
	{
		for (int j=i+m-1;j<n;j++)
		{
			x=a[i+1];
			for (int k=i+1;k<=j;k++)
			{
				x=(x&a[k-1]);
			}
			maxx=max(maxx,x);
		}
	}
	cout<<maxx;
	return 0;
}
