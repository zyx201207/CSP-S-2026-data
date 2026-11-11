#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 500010;

int n, m;
int a[N];
int q[N];
int st[N], cnt[N];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	bool flag = true;
	for (int i = 1; i <= n; i ++ ) 
	{
		scanf("%d", &a[i]);
		if (a[i] < a[i - 1]) flag = false;
	}
	
	if (!flag)
	{
		for (int i = 1; i <= n; i ++ )
		{
			memset(st, -1, sizeof st);
			int hh = 0, tt = -1;
			for (int j = i; j <= n; j ++ )
			{
				if (st[a[j]] == -1) 
				{
					q[ ++ tt] = a[j];
					st[a[j]] = tt;
				}
				else
				{
					int backup = tt;
					tt = st[a[j]];
					q[tt] = a[j];
					st[a[j]] = tt;
				
					for (int k = tt + 1; k <= backup; k ++ ) st[q[k]] = -1;
					for (int k = hh; k <= tt; k ++ ) st[q[k]] = k;
				}
			}
			for (int j = hh; j <= tt; j ++ ) cnt[q[j]] ++ ;
		}
	
		for (int i = 1; i <= m; i ++ ) printf("%d ", cnt[i]);
	}
	else
	{
		for (int i = 1; i <= n; i ++ )
			if (a[i] != a[i - 1]) cnt[a[i - 1]] = i - 1;
		cnt[a[n]] = n;
		
		for (int i = 1; i <= m; i ++ ) printf("%d ", cnt[i]);
	}
	
	return 0;
}
