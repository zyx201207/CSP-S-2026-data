#include<bits/stdc++.h>
#define ll int
using namespace std;
struct aaa
{
	ll now;
	ll last;
	ll i;	
};
aaa cf[1000005];
ll a[1000005];
bool cmp(aaa a, aaa b)
{
	return a.last < b.last;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n, m;
	cin >> n >> m;
	for(ll i = 1;i <= n; i++)
	{
		cin >> a[i];
		cf[i].last = a[i];
		cf[i].i = i;
	}
	if(n == m)
	{
		int k = a[1];
		for(int i = 2;i <= n; i++)
		{
			//cout << k << endl;
			k = int(k & a[i]);
		}
		cout << k;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	for(ll i = 1;i <= n; i++)
	{
		cf[i].now = cf[i].last - cf[i - 1].last ;
	}
	sort(cf + 1, cf + 1 + n,cmp);
	ll minn = 0x3f3f3f3f;
	ll j = 0;
	for(ll i = 1;i <= n; i++)
	{
		ll k = 0;
		for(ll l = 1;l <= m; l++)
		{
			k += cf[i + l].last ;
		}
		if(minn > k)
		{
			minn = k;
			j = i;
		}
	}
	int ans = cf[j].last ;
	//cout << j << endl;
	for(ll i = 1;i < m; i++)
	{
		//cout << cf[j - i].last << endl;
		ans = int(ans & cf[j - i].last);
	}
	cout << ans;
	return 0;
} 
