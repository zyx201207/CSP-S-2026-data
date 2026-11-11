#include <bits/stdc++.h>
using namespace std;
int n, m, x[1000001], a[10000001];
queue<int> q;
queue<int> p;
void ab(int m)
{
	while(true)
	{
		if(q.back() == q.front())
		{
			q.pop();
			if(q.size() != 0)
				q.pop();
			break;
		}
		else
		{
			p.push(q.front())
			q.pop();
		}
	}
	for(int i = 1; i <= m; i++)
	{
		int a[i] = 0;
		if(q.front == i)
		{
			a[i]++;
		}
	}
	cout << a[i] << " ";
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	while(n--)
	{
		for(int i = n; i >= 1; i--)
		{
			cin >> x[i];
			q.push(x[i]);
			ab();
		}
	}
	return 0;
}
