#include<bits/stdc++.h>

using namespace std;
const int N = 5e5+5;
int n, l, r, ans = 0;
long long m, cur = 0, a[N], diff[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++)
	{
		diff[i] = a[i]-a[i-1];
	}
	l = 1, r = 0;
	while(l<=n)
	{
		while(cur<=m)
		{
			ans = max(ans, r-l+1);
			if(r+1<=n)
			{
				r++;
				cur += 1ll*(r-l)*diff[r];
			}
			else
			{
				break;
			}
		}
		cur -= (a[r]-a[l]);
		l++;
	}
	cout << ans;
	
	return 0;
}
