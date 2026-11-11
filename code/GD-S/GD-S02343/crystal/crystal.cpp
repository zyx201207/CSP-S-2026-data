#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], cur, ans, hav;
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int l=1, r=1;
	hav=m;
	ans=1;
	cur=1;
	while (l<=n && r<=n)
	{
		r++;
		hav-=(r-l)*(a[r]-a[r-1]);
		cur++;
		while (hav<0 && l<=n)
		{
			hav+=a[r]-a[l];
			cur--;
			l++;
		}
		ans=max(ans, cur);
	}
	cout << ans << endl;
	return 0;
}
