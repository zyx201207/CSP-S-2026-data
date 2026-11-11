#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[5000005],mid,ans = -1;
ll check(ll x,ll sum,ll crystal,ll b[5000005])
{
	for(ll i = 1;i<=x;i++)
	{
		b[i] -= b[x];
		b[i] = abs(b[i]);
	}
	for(ll i = x;i>=1;i--)
	{
		if(crystal >= b[i])
		{
			crystal-=b[i];
			sum++;
		}
		else if(crystal == 0) break;
	}
	for(ll i = x+1;i<=n;i++)
	{
		if(b[i] == b[x]) sum++;
		else break;
	}
	return sum;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n % 2 != 0) mid = (n+1)>>1;
	else mid = n>>1;
	for(ll i = mid;i<=n;i++)
	{
		ll tmp = check(i,0,m,a);
		if(tmp >= ans) ans = tmp;
	}
	cout<<ans;
	return 0;
}
