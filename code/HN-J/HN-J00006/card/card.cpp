#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5e5 + 10;

int n, m;
int a[N], lst[N], vis[N];
int ans[N], temp[N];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof vis);
		memset(lst, 0, sizeof lst);
		memset(temp, 0, sizeof temp);
		for (int j = i; j <= n; j++)
		{
			//如果上一个数字出现过
			//把它及它以后的数字全部打上标签 
			if (lst[a[j]])
			{
				for (int k = lst[a[j]]; k < j; k++) vis[k] = 1;
			}
			//修改它最后出现的位置 
			lst[a[j]] = j;
		}
	 
		for (int j = i; j <= n; j++)
		{
			if (!vis[j]) temp[a[j]]++;
			//cout << "j=" << j << " " << vis[j] << " ";
		}
		for (int j = 1; j <= m; j++)
		{
			if (temp[j]) ans[j]++;
		}
	}
	
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
