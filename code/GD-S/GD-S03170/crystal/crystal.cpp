#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, cnt = 1;
	ll m;
	cin >> n >> m;
	vector<ll> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a.begin() + 1, a.begin() + n + 1);
	for(int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] + a[i];
	for(int l = 1, r = 1; r <= n; l ++)
	{
		if(r < l)r = l;
		int len = r - l + 1;
		while(r <= n && len * a[r] - (pre[r] - pre[l - 1]) <= m)
		{
			r ++;
			len ++;
		}
		if(r > n)cnt = max(cnt, len);
		else cnt = max(cnt, len - 1);
	}
	cout << cnt;
} 
