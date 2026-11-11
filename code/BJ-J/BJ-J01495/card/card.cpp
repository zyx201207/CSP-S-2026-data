#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt[3005],ans[3005],qc[10005],asd[10005],cunt;
stack<int> st2;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	bool fl = true;
	for (int i = 1;i < n;i++)
	{
		if (a[i] > a[i + 1])
		{
			fl = false;
			break;
		}
	}
	if (fl)
	{
		for (int i = 1;i < n;i++)
			if (a[i] != a[i + 1])
				cout << i << ' ';
		cout << n;
		return 0;
	}
	if (n > 5000)
	{
		qc[++cunt] = a[1];
		for (int i = 2;i <= n;i++)
		{
			if (a[i] != a[i - 1])
			{
				qc[++cunt] = a[i];
				asd[cunt - 1] = i - 1;
			}
		}
		asd[cunt] = n;
		for (int i = 1;i <= cunt;i++)
		{
			while (st2.size())
				st2.pop();
			for (int j = 1;j <= m;j++)
				cnt[j] = 0;
			for (int j = i;j <= cunt;j++)
			{
				if (cnt[qc[j]])
				{
					while (st2.top() != qc[j])
					{
						int x = st2.top();
						st2.pop();
						cnt[x]--;
					}
				}
				else
				{
					st2.push(qc[j]);
					cnt[qc[j]]++;
				}
			}
			for (int j = 1;j <= m;j++)
				if (cnt[j])
					ans[j] += asd[i] - asd[i - 1];
		}
		for (int i = 1;i <= m;i++)
			cout << ans[i] << ' ';
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		while (st2.size())
			st2.pop();
		for (int j = 1;j <= m;j++)
			cnt[j] = 0;
		for (int j = i;j <= n;j++)
		{
			if (cnt[a[j]])
			{
				while (st2.top() != a[j])
				{
					int x = st2.top();
					st2.pop();
					cnt[x]--;
				}
			}
			else
			{
				st2.push(a[j]);
				cnt[a[j]]++;
			}
		}
		for (int j = 1;j <= m;j++)
			if (cnt[j])
				ans[j]++;
	}
	for (int i = 1;i <= m;i++)
		cout << ans[i] << ' ';
	return 0;
}
