#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], maxx, ans;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for (int r=1, l=1; r<=n; r++)
	{
		ans=ans+(a[r]-a[r-1])*(r-l);
		while (l<r && ans>m)
		{
			l++;
			ans=ans-(a[r]-a[l]);
		}
		maxx=max(maxx, r-l+1);
	}
	cout << maxx;
	return 0;
}
