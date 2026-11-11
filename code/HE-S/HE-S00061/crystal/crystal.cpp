#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
ll n,m,a[maxn],sum[maxn],d[maxn];
ll maxv;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(ll i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	ll l=0;
	for(ll i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+d[i]*(i-l-1);
		while(sum[i]>m)
		{
			l++;
			sum[i]-=a[i]-a[l];
			if(l>n)break;
		}
		maxv=max(maxv,i-l);
	}
	cout << maxv;
	return 0;
}
