#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m, a[N], d[N], tmp = 1, ans;
//vector<pair<int, int> > vt;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		d[i] = a[i] - a[i - 1];
//		cout << a[i] << ' ';
	}
//	cout << "\n";
	for(int i = 1;i <= n;i++)
	{
		long long count = i * d[i + 1];
//		cout << count << " " << tmp << " " << m << "\n";
		if(count > m)
		{
			cout << tmp;
			return 0;
		}
		m -= count;
		tmp++;
		ans = max(tmp, ans);
	}
//	cout << m << "\n";
	cout << min(ans, n);
	return 0;
}
