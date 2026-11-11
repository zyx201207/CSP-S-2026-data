#include<bits/stdc++.h>
using namespace std;
long long a[500001], h[500001];
int n, m;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		h[i]=h[i-1]+a[i];
	}
	sort(a+1, a+n+1);
	for (int i=1;i<=n;i++)
	{
		h[i]=h[i-1]+a[i];
	}
	long long anss=0;
	for (int i=1;i<=n;i++)
	{
		long long l=1, r=i, mid, ans;
		while (l<=r)
		{
			mid=(l+r)/2;
			if (a[i]*(i-mid+1)-(h[i]-h[mid-1])<=m)
			{
				ans=i-mid+1;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		anss=max(ans, anss);
	}
	cout<<anss<<endl;
	return 0;
}
