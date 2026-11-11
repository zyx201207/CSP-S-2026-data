#include<bits/stdc++.h>

using namespace std;
const int N = 5e5+5, M = 3e5+5;
int n, m, sz, a[N], ans[M], card[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		sz = 0;
		for(int j = i; j <= n; j++)
		{
			for(int k = 1; k <= sz; k++)
			{
				if(card[k]==a[j])
				{
					sz = k-1;
					break;
				}
			}
			card[++sz] = a[j];
		}
		for(int j = 1; j <= m; j++)
		{
			for(int k = 1; k <= sz; k++)
			{
				if(card[k]==j)
				{
					ans[j]++;
					break;
				}
			}
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	
	return 0;
}
