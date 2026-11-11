#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> a[35];
long long ans;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		long long x;
		cin >> x;
		for (int i = 0;i <= 30;i++)
		{
			if ((x >> i) & 1) a[i].push_back(x);
		}
		a[31].push_back(x);
	}
	for (int i = 0;i <= 31;i++) sort(a[i].begin(), a[i].end());
	for (int i = 30;i >= 0;i--)
	{
		int cnt = 0;
		int p = 0, q = 0;
		vector<long long> v;
		for (;p < a[31].size() && q < a[i].size();)
		{
			if (a[31][p] == a[i][q])
			{
				v.push_back(a[31][p]);
				cnt++;
				p++;
				q++;
			}
			else if (a[31][p] > a[i][q]) q++;
			else p++;
		}
		if (cnt >= m)
		{
			ans |= 1 << i;
			a[31].clear();
			for (int j = 0;j < v.size();j++)
			{
				a[31].push_back(v[j]);
			}
		}
	}
	cout << ans;
	return 0;
}
