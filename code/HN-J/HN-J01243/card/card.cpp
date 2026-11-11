#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005];

int l[300005], r[300005], nxt[500005];
bool f[300005];
int sub[500005];
int ans[300005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		if(r[a[i]] > 0)
		{
			nxt[r[a[i]]] = i;
		}
		if(l[a[i]] == 0)
		{
			l[a[i]] = i;
		}
		r[a[i]] = i;
	}
	priority_queue < int, vector <int>, greater <int> > q;
	priority_queue <int> q2;
	for(int i = 1; i <= m; i ++)
	{
		if(l[i] < r[i])
		{
			q.push(l[i]);
			q2.push(r[i]);
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		if(q.size() == 0)
		{
			break;
		}
		for(; q2.size() > 0 && f[a[q2.top()]] == true; q2.pop());
		sub[q.top()] ++;
		sub[q2.top()] --;
		if(q.top() == i)
		{
			q.pop();
			if(nxt[i] < r[a[i]])
			{
				q.push(nxt[i]);
			}
			else
			{
				f[a[i]] = true;
			}
		}
	}
	int num = 0;
	for(int i = 1; i <= n; i ++)
	{
		num += sub[i];
		ans[a[i]] = max(ans[a[i]], i - num);
	}
	for(int i = 1; i <= m; i ++)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}
