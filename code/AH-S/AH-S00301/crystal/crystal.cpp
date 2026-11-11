#include<bits/stdc++.h>
using namespace std;
long long a[500010],sum[500010];
long long n,m,ans;
long long bs(int lft)
{
	int l=lft,r=n,mid,k=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(1ll*(mid-lft)*a[lft]-sum[mid]+sum[lft]<=m)
		{
			k=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return k;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,bs(i)-1ll*i+1ll);
		if(ans==n-i+1)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}

