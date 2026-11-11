#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m;
ll a[1000005],f[200005],st,res[200005],ans,cntt;
void zh(ll x)
{
	ll cnt = 0;
	while(x)
	{
		cnt++;
		if(x % 2 == 1) f[cnt]++;
		x /= 2;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n;i++)
	{
		cin >> a[i];
		zh(a[i]);
	}
	for(ll i = 200000;i >= 1;i--)
	{
		if(cntt == m) break;
		if(f[i] >= m)
		{
			if(st == 0) st = i; 
			res[i] = 1; 
			cntt++; 
		}
	}
	for(ll i = st;i >= 1;i--)
	{
		ans += res[i] * pow(2,i-1); 
	}
	cout << ans;
	return 0;
}
