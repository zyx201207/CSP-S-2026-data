#include<bits/stdc++.h>
using namespace std;
int n,m,a,mx;
queue<int> q1,q2,q3;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		mx = max(a,mx);
		q1.push(a);
	}
	int cnt = 0;
	while ((1 << cnt) <= mx)
		cnt++;
	cnt--;
	for (int i = cnt;i >= 0;i--)
	{
		while (q1.size())
		{
			int x = q1.front();
			q1.pop();
			q3.push(x);
			if (x & (1 << i))
				q2.push(x);
		}
		if (q2.size() >= m)
		{
			while (q2.size())
			{
				int x = q2.front();
				q2.pop();
				q1.push(x);
			}
		}
		else
		{
			while (q3.size())
			{
				int x = q3.front();
				q3.pop();
				q1.push(x);
			}
		}
		while (q2.size()) q2.pop();
		while (q3.size()) q3.pop();
	}
	int ans = (1 << 31) - 1;
	while (q1.size())
	{
		ans &= q1.front();
		q1.pop();
	}
	cout << ans;
	return 0;
}
