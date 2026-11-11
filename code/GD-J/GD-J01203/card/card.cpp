#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N];
int ans[N];
int w[N];
int du[N];
int sz[N];
vector<int> e[N];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = n; i > 0; i--)
	{
		if(!w[a[i]]) w[a[i]] = i;
		int lst = w[a[i]];
		e[i].push_back(lst + 1);
		du[lst + 1]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
		sz[i] = 1;
	for(int i = 1; i <= n; i++)
		if(!du[i]) q.push(i);
	while(q.size())
	{
		int x = q.front();
		q.pop();
		ans[a[x]] += sz[x];
		for(auto v : e[x])
		{
			du[v]--;
			sz[v] += sz[x];
			if(du[v] == 0) q.push(v);
		}
	}
	for(int i = 1; i <= m; i++)
		printf("%d%c", ans[i], (i == m ? '\n' : ' '));
	return 0;
}
