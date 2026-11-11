#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long n,m,a[500005],ans1,ans=-1,m1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	if(m==0)
	{
		cout<<1;
		return 0;
	}
	m1=m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll t=n/2+1;t<=n;t++)
	{
		ans1=0;
		m1=m;
		if(a[t]!=a[t-1])
		{
			for(ll i=1;i<=n;i++)
			{
				if(a[i]<=a[t]&&m1-(a[t]-a[i])>=0&&m1>=0)
				{
					m1-=(a[t]-a[i]);
					ans1++;
				}
			}
		}
		ans=max(ans,ans1);		
	}
	cout<<ans;
	return 0;
}
