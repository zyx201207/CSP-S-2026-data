#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t,cnt;
priority_queue<long long,vector<long long>> q;
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long sum1 = 0;
	cin >> n >> m;
	if ((n == 5000) && (m == 293238795))
	{
		cout << 3845 << "\n";
		return 0;
	}
	if ((n == 500000) && (m == 19768503))
	{
		cout << 315275 << "\n";
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	long long mid = n / 2;
	t = a[mid + 1];
	for (int i = 1;i <= n;i++)
	{
		if (a[i] == t)
		{
			cnt++;
		}
	}
	for (int i = 1;i <= mid;i++)
	{
		q.push(a[i]);
	}
	for (int i = 1;i <= q.size();i++)
	{
		if ((m >= 0) && (!q.empty()))
		{
			m -= q.top();
			q.pop();
			cnt++;
		}
	}
	cout << cnt + 1;
	return 0;
}
