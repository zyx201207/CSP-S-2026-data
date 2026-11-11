#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans,tmp[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll sum = 0,minn = LLONG_MAX;
	for(int i = 1;i<=n;i++) cin>>a[i],sum += a[i];
	sum/=n;
	for(int i = 1;i<=n;i++)
	{
		if(abs(a[i]-sum)<=abs(minn-sum)) minn = a[i];
		tmp[i] = a[i];
	}
	for(int j = 0;j<=m/n;j++)
	{
		ll tm = m,tans = 0;
		minn += j;
		for(int i = 1;i<=n;i++) tmp[i] = minn-tmp[i];
		sort(tmp+1,tmp+n+1);
		for(int i = 1;i<=n;i++)
		{
			if(tm>=tmp[i]&&tmp[i]>=0) tans++,tm-=tmp[i];
			else {if(tm<tmp[i]) break;}
		}
		ans = max(ans,tans);
	}
	cout<<ans;
	return 0;
}

