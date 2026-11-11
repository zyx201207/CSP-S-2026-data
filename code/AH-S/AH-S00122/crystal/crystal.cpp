#include<bits/stdc++.h>
using namespace std;
long long n,m,anss,a[500010],s[500010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long l=i,r=n,ans=0;
		while(l<=r)
		{
			long long mid=(l+r)>>1;
			if(a[mid]*(mid-i+1)-s[mid]+s[i-1]<=m)
			{
				ans=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
//		cout<<i<<' '<<ans<<'\n';
		anss=max(anss,ans-i+1);
	}
	cout<<anss;
	return 0;
}
