#include<bits/stdc++.h>
using namespace std;
const long long N = 5e6+10;
long long n, m, vis[N], b[N];
long long a[N];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	for(int i = 1; i <= n; i++)
	{
		int cnt = 0;
		queue<int> q;
		for(int j = i; j <= n; j++)
		{
			queue<int> q1;
			while(!q.empty()&&a[j]!=q.front())
			{
				q1.push(q.front());
				q.pop();
			}
			while(!q1.empty()&&q1.front()!= a[j])
			{
				q.push(q1.front());
				q1.pop();
			}
			q.push(a[j]);
		}
		while(!q.empty())
		{
			vis[q.front()]++;
			q.pop();
		}
	}
	for(int i = 1; i <= m; i++)
	{
		if(b[i]==1) vis[i] = n;
		cout << vis[i] << " ";
	}
	return 0;
}
