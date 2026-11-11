#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

int c, t;

int n, d;
int a[2000010];

int ans = 0;

void DFS(int start_id, int ending_id, int this_lenth, vector<int> &lenth, int &min_lenth)
{
	if (start_id == ending_id)
	{
		lenth.push_back(this_lenth);
		min_lenth = min (min_lenth, this_lenth);
	}
	for (int i = start_id + 1; i <= ending_id; i++)
	{
		if (a[i] - a[start_id] > d)
			break;
		DFS(i, ending_id, this_lenth + 1, lenth, min_lenth);
	}
}

signed main ()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int u = 1; u <= n ; u++)
		{
			for (int v = u + 1; v <= n; v++)
			{
				vector<int> lenth;
				int min_lenth = 9999999999999;
				DFS(u, v, 0, lenth, min_lenth);
				int cnt = 0;
				for (auto it : lenth)
				{
					if (it == min_lenth)
					{
						cnt++;
					}
				} 
				if (cnt == 2)
				{
					ans++; 
				}
//				//²âÊÔ´úÂë
//				cout << u << " " << v << " : " << cnt << "\n";
//				for (auto it : lenth)
//				{
//					cout << it << " ";
//				}
//				cout << "\n"; 
//				//²âÊÔ´úÂë 
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
