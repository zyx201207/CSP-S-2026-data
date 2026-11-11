#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], vis[300005], sum[300005];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		stack <int> q;
		for(int j = i;j <= n;j++)
		{
			int x = a[j];
			if(vis[x] == 0)
			{
				q.push(x);
				vis[x] = 1;
			}
			else {
				while(!q.empty())
				{
					int y = q.top();
					vis[y] = 0;
					if(y == x)
					{
						break;
					}
					q.pop();
					
				}
				vis[x] = 1;
			}
		}
		while(!q.empty())
		{
			int y = q.top();
			vis[y] = 0;
			sum[y]++;
			q.pop();
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << sum[i] << " ";
	}
	return 0;
}
