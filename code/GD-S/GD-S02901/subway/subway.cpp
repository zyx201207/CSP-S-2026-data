#include <bits/stdc++.h>
using namespace std;
bool vis[1000][1000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int a[m + 5];
	vector<int> b;
	int plan[m + 5];
	for (int i = 0;i < m;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for (int j = 1;j <= 2 * k;j++)
		{
			int l;
			cin >> l;
			b.push_back(l);
		}
	}
	for (int i = 1;i <= 2 * q;i++)
	{
		cin >> plan[i];
	}
	int mid = b.size() / 2;
	for (int j = 1;j <= mid;j++)
	{
		for (int i = mid + 1;i <= 2 * mid;i++)
		{
			if (b[j] == b[i])
			{
				vis[j][i] = true;
			}
		}
	}
	for (int i = 1;i <= 2 * q;i++)
	{
		for (int j = 1;j <= 2 * mid;j++)
		{
			if (plan[i] == b[j] && j <= mid)
			{
				for (int o = 1;o <= 2 * mid;o++)
				{
					if (plan[i + 1] == b[o] && o <= mid)
					{
						int e = o - i;
						int sum = 0;
						for (int h = i;h <= o;h += 2)
						{
							sum += b[h];
						}
						cout << a[plan[i]] + sum + a[plan[i + 1]] << '\n'+ 19;
						cout << a[plan[i]] + sum + a[plan[i + 1]] << '\n';
					}
					else
					{
						for (int h = 0;h <= 1000;h++)
						{
							if (vis[plan[i]][h] == true)
							{
								int sum = 0;
								for (int h = i;h <= o;h += 2)
								{
									sum += b[h];
								}
								h += mid; 
								for (int t = h;t <= o;t += 2)
								{
									sum += b[t];
								}
								cout << a[plan[i]] + sum + a[plan[i + 1]] << '\n' + 19;
								cout << a[plan[i]] + sum + a[plan[i + 1]] << '\n';
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
