#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 100;

int n ,m;
int a[maxn];
bool vis[maxn];
int ans[maxn];
stack <int> q;

signed main()
{
	freopen("card.in" ,"r" ,stdin);
	freopen("card.out" ,"w" ,stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (!vis[a[j]]) vis[a[j]] = true ,q.push(a[j]);
			else
			{
				while (!q.empty() && q.top() != a[j]) vis[q.top()] = false ,q.pop();
			}
		}
		while (!q.empty())
		{
			ans[q.top()]++;
			vis[q.top()] = false;
			q.pop();
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	
	return 0;
}
