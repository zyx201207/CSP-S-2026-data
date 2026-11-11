#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[500005];
ll c[300005];
ll last[300005];
void solve()
{
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	ll n;
	cin >> n;
	ll m;
	cin >> m;
	bool f = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] < a[i-1])
		{
			f = 1;
		}
	}
	if(f == 0)
	{
		ll cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			cnt++;
			if(a[i] != a[i+1])
			{
				cout << cnt << " ";
				
			}
		}
		return;
	}
	
	for(int j = 1;j <= n;j++)
	{
		last[a[j]] = j+1;
	}
	for(int j = 1;j <= n;j++){
		ll i = j;
		while(i <= n)
		{
			c[a[i]]++;
			i = last[a[i]];
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << c[i] << " ";
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	solve();
	return 0;
}
