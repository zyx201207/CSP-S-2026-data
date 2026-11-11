#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxn,minn,mid;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		if(a[i] >= maxn)
		{
			maxn = a[i];
		}
		if(a[i] <= minn)
		{
			minn = a[i];
		}
	}
	mid = 1;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != minn && a[i] < maxn && a[i] > mid)
		{
			mid = a[i];
			break;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != minn && a[i] < maxn && a[i] < mid)
		{
			mid = a[i];
		}
	}
	cout<<mid;
	return 0;
}
