#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
bool check(int num)
{
	for(int i=1;i+num-1<=n;i++)
	{
		int j=i+num-1;
		long long sum=b[j-1]-b[i-1];
		if(a[j]*(num-1)<=sum+m)return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	int l=0,r=n,mid,ans=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	
	return 0;
}
