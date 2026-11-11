#include<bits/stdc++.h>
using namespace std;

long long n, m, ans[300005];
struct num
{
	long long val, pos;
} a[500005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].val;
		a[i].pos = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int che[300005];
		memset(che, -1, sizeof(che));
		for (int j = i; j <= n; j++)
		{
			if(che[a[j].val] + 1) 
			{
				for (int e = 1; e <= m; e++)
				{
					if(che[e] > che[a[j].val]) che[e] = -1;
				}
			}
			else
			{
				che[a[j].val] = a[j].pos;
			}
		}
		for(int j = 1; j <= m; j++)
		{
			if(che[j] + 1 != 0)
				ans[j]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
