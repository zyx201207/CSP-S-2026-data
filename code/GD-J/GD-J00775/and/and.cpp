#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll a[200001];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	if(m == 1)
	{
		ll maxn = INT_MIN;
		for(int i = 1; i <= n; i ++)
		{
			maxn = max(maxn, a[i]);
		}
		cout << maxn << "\n"; 
	}
	else if(m == 2)
	{
		ll maxn = INT_MIN;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = i + 1; j <= n; j ++)
			{
				maxn = max(maxn, (a[i] & a[j]));
			}
		}
		cout << maxn << "\n";
	}
	else if(n == m)
	{
		ll ans = a[1];
		for(int i = 2; i <= n; i ++)
		{
			ans &= a[i];
		}
		cout << ans << "\n";
	}
	else
	{
		ll s[33];
		memset(s, 0, sizeof(s));
		ll ans = 0;
		for(int i = 1; i <= n; i ++)
		{
			int temp = 0;
			while(a[i])
			{
				if(a[i] % 2 == 1)
				{
					s[temp] ++; 
				}
				a[i] >>= 1;
				temp ++;
			}
		}
		int t = m;
		for(int i = 32; i >= 1 && t; i --)
		{
			if(s[i] >= m)
			{
				ans += pow(2, i); 
				t --; 
			}
		}
		cout << ans << "\n"; 
	}
	return 0;
}
