#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],l,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
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
	for(int i=1;i<=n;i++)
	{
		while(a[i]*(i-l)-(sum[i]-sum[l])>m)
		{
			l++;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}
