#include <bits/stdc++.h>
using namespace std;

const int NR = 5e5 + 5;

map<int, int> cnt, cnt_n;

int a[NR], now[NR], l[NR];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		int t = 0;
		memset(now, 0, sizeof(now));
		memset(l, 0, sizeof(l));
		cnt_n.clear();
		for(int j = i; j <= n; j++)
		{
			if(cnt_n[a[j]] == 0)
			{
				now[++t] = a[j];
				cnt_n[a[j]]++;
				l[a[j]] = t;
			}
			else
			{
				for(int k = l[a[j]] + 1; k <= t; k++)
				{
					cnt_n[now[k]] --;
					l[now[k]] = 0;
					now[k] = 0;
				}
				t = l[a[j]];
			}
		}
		for(int j = 1; j <= t; j++) cnt[now[j]] ++;
	}
	for(int i = 1; i <= m; i++) cout << cnt[i] << " ";
	return 0;
}
