#include<bits/stdc++.h>
using namespace std;

int n;
long long a[500005],m;

bool check(int x)
{
	long long cnt=m;
	for(int i=1;i<x;i++)
	{
		if(a[x]-a[i]>cnt)return 0;
		cnt-=a[x]-a[i];
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			int ans=0;
			int cnt=m;
			for(int j=i;j>=1;j--)
			{
				if(a[i]-a[j]>cnt)break;
				ans++;
				cnt-=a[i]-a[j];
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
		return 0;
	}
	else
	{
	int l=1,r=n;
	while(r-l>5)
	{
		int mid=(r+l)>>1;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	for(int i=r;i>=l;i--)
	{
		if(check(i))
		{
			cout<<i;
			return 0;
		}
	}
	}

	return 0;
}
