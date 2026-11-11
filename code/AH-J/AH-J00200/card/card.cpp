#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 5e5 +5, MAXM = 3e5 + 5;
ll n, m, cnt[MAXM];
ll a[MAXN];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++)
	{
	 	cin >> a[i];
	}
	for(ll j = 1; j <= n; j++)
	{
		ll r[MAXM];
		for(ll i = 1; i <= m; i++) r[i] = 0;
		ll up[MAXM], ans = 0;
		for(ll i = j; i <= n; i++)
		{
			if(r[a[i]] == 0)
			{
				up[ans + 1] = a[i];
			}
			else
			{
				for(ll k = r[a[i]] + 1; k <= ans; k++)
				{
					if(r[up[k]] == k) r[up[k]] == 0;
				}
				ans = r[a[i]];
			}
		}
		for(ll i = 1; i <= ans; i++)
		{
			cnt[up[i]]++;
		}
	}
	for(ll i = 1; i <= m; i++)
	{
		cout << cnt[i] << " "; 
	}
	return 0;
} 
