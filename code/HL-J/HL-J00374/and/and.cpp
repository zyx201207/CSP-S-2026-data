#include<bits/stdc++.h>
using namespace std;
int n, m, a[223123], ls[223123], rs[223123];
int popcnt(int val)
{
	int ans = 0;
	for(int i = 0; i < 32; i++)
		if(val >> i & 1)
			ans++;
	return ans;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0); 
	cin >> n >> m;
	memset(ls, -1, sizeof ls);
	memset(rs, -1, sizeof rs);
	for(int i = 0; i < n; i++)
		cin >> a[i], ls[i + 1] = ls[i] & a[i];
	if(m == 1)
	{
		cout << *max_element(a, a + n);
		return 0;
	}
	if(m == n)
	{
		int ans = a[0];
		for(int i = 1; i < n; i++)
			ans &= a[i];
		cout << ans;
		return 0;
	}
	if(m == 2)
	{
		int mx = 0;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				mx = max(mx, a[i] & a[j]); 
		cout << mx;
		return 0;
	}
	if(m == n - 1)
	{
		int mx = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			rs[i] = rs[i + 1] & a[i];
		}
		for(int i = 0; i < n; i++)
			mx = max(mx, ls[i] & rs[i + 1]);
		cout << mx;
		return 0;
	} 
	int mx = 0;
	for(int i = 0; i < 1 << n; i++)
	{
		if(popcnt(i) == m)
		{
			int ans = -1;
			for(int j = 0; j < n; j++)
				if(i >> j & 1)
					ans &= a[j];
			mx = max(mx, ans);
		}
	}
	cout << mx;
	return 0;
	//Avada Kedavra
	//Ich brauche AK
} 
