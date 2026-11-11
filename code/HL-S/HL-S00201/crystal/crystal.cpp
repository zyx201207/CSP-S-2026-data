#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int l = 0, r = 0;
	int ans = 1;
	long long cur = 0;
	while(r < n)
	{
		if(cur <= m)
		{
			ans = max(ans, r - l + 1);
			r++;
			if(r < n) cur += (r - l) * (a[r] - a[r - 1]); 
		}
		else
		{
			l++;
			cur -= (a[r] - a[l - 1]);
		}
	}
	cout << ans << endl;
	return 0;
}
