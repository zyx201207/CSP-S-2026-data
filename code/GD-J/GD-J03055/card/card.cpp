#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long last[300005];
long long jmp[500005];
vector<long long> v[500005];
long long ru[500005];
long long sum[500005];
bool vis[500005];
long long know[500005];
long long ans[500005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++) cin >> a[i];
	for(long long i = n; i >= 1; i--)
	{
		if(last[a[i]] == 0) last[a[i]] = i, jmp[i] = 0;
		else jmp[i] = last[a[i]], last[a[i]] = i;
	}
	know[n] = a[n];
	for(long long i = n - 1; i >= 1; i--)
	{
		if(jmp[i] != 0) v[i].push_back(jmp[i]), ru[jmp[i]]++;
		else know[i] = a[i], v[i].push_back(i + 1), ru[i + 1]++;	
	}
	priority_queue<long long, vector<long long>, greater<long long>> q;
	for(long long i = 1; i <= n; i++) 
	{
		sum[i] = 1;
		if(ru[i] == 0) q.push(i), vis[i] = 1;
	}
	while(!q.empty())
	{
		long long x = q.top();
		q.pop();
		for(long long i = 0; i < v[x].size(); i++)
		{
			long long y = v[x][i];
			sum[y] += sum[x];
			if(!vis[y])
			{
				vis[y] = 1;
				q.push(y);
			}
		}
	}
	for(long long i = 1; i <= n; i++) ans[know[i]] += sum[i];
	for(long long i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
