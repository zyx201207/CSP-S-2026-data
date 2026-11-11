#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],sum[N];
int need(int l,int r)
{
	int cnt=r-l+1;
	int summ=cnt*a[r];
	int now=sum[r]-sum[l-1];
	return summ-now;
}
signed main()
{
//	ios::sync_stdio_with(false);
	freopen("crystal.in","r",stdin);
	freopen("crysral.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=1;
	int ans=1;
	while(r<=n)
	{
		if(need(l,r)<=m)
		{
			ans=max(ans,r-l+1);
			r++;
		}
		else
		{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
