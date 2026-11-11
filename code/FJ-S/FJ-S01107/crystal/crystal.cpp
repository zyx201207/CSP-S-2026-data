#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l=1,r;
int a[500005],qzh[500005];
int check(int num)
{
	for(int i=num;i<=n;i++)
	{
		if(num*a[i]-(qzh[i]-qzh[i-num])<=m)
		{
			return 1;
		}
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	r=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		qzh[i]=qzh[i-1]+a[i];
	}
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid)==1)
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l;
}
