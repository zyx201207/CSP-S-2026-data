#include <bits/stdc++.h>
using ll=long long;
using namespace std;
ll a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,i,j,dc;
	bool pda=1,pdb=1;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (a[i]!=i)
		{
			pda=0;
		}
		if (i==2)
		{
			dc=a[i]-a[i-1];
		}
		else
		{
			if (a[i]-a[i-1]!=dc)
			{
				pdb=0;
			}
		}
	}
	if (pda)
	{
		cout << ll((-1+sqrt(1+8*m))/2)+1;
		return 0;
	}
	else if (pdb)
	{
		cout << ll((-dc+sqrt(8*m*dc))/2*dc)+1;
		return 0;
	}
	sort(a+1,a+n+1);
	if (m==0)
	{
		ll ans=0,len=1;
		for (i=2;i<=n;i++)
		{
			if (a[i]!=a[i-1])
			{
				ans=max(ans,len);
				len=0;
			}
			len++;
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1);
	ll ans=1;
	for (i=2;i<=n;i++)
	{
		ll sum=0,cnt=1;
		for (j=i-1;j;j--)
		{
			sum+=a[i]-a[j];
			if (sum<=m)
			{
				cnt++;
			}
			else
			{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout << ans;
	return 0;
}
