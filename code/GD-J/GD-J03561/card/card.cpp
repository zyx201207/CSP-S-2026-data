#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, sum = 1;
	cin >> n >> m;
	vector<int> a(n + 1), r(n + 1), vis(m + 1), cnt(m + 1), c(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if(vis[a[i]])
			r[vis[a[i]]] = i;
		vis[a[i]] = i;
	}
	for(int i = 1; i <= n; i ++)
	{
		if(r[i])
		{
			c[r[i]] += sum + c[i];
			sum = 1;
		}
		else 
		{
			sum += c[i];
			cnt[a[i]] += sum;
			c[i + 1] ++;
		}
	}
	for(int i = 1; i <= m; i ++)
		cout << cnt[i] << ' ';
}
