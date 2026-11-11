#include <bits/stdc++.h>//Ç°×ººÍ¡££¿ 
using namespace std;
#define ll long long

const int N = 500005;
const int M = 300005;
ll a[N];
ll ans[M];
bool pd[M];
bool pdd = true;

ll f(ll x)
{
	ll cnt(1);
	for (ll i = x - 1; i >= 1; i--)
	{
		if (!pd[a[i]] && (a[i] != a[x]))
			cnt++;
		else 
			break;
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	ll jsq(0);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	
	for (int i = 2; i <= n; i++)
	{
		if (a[i] < a[i-1])
		{
			pdd = false;
		}
	}
	if (pdd)
	{
		for (int i = n; i >= 1; i--)
		{
			if (!pd[a[i]])
			{
				ans[a[i]] = i;
				pd[a[i]] = true;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			cout << ans[i] << ' ';
		}
		return 0;
	}
	
	
	
	jsq = a[n];
	ans[a[n]] = n;
	for (int i = n; i >= 1; i--)
	{
		if (a[i] != a[n])
			ans[a[i]] += f(i);
		pd[a[i]] = true;
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
} 


