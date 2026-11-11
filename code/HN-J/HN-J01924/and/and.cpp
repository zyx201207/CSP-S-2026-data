#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],maxn=0;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=a[1];
	if(n==m)
	{
		for(int i=2;i<=n;i++)
		{
			sum&=a[i];
		}
	}
	if(n==m+1)
	{
		for(int i=2;i<=n;i++)
		{
			sum&=a[i];
		}
	}
	maxn=0;
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,sum&a[i]);
	}
	cout<<maxn;
	return 0;
}

