#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m, a[N], ans[M];
bool vis[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int round = 1; round <= n; round++)
	{
		memset(vis, 0, sizeof vis);
		vector<int> stk;
		for(int i = round; i <= n; i++)
		{
			if(vis[a[i]] == 0)
			{
				vis[a[i]] = 1;
				stk.push_back(a[i]);
				ans[a[i]]++;
			}
			else
			{
				while(stk.back() != a[i])
				{
					vis[stk.back()] = 0;
					stk.pop_back();
					ans[a[i]]--;
				}
			}
		}
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}
