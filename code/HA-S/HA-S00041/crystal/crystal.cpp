#include<bits/stdc++.h>

#define int long long 
#define N 500010

using namespace std;

int n, m;
int a[N];
int c[N];
int sum[N];
int ans;
bool f1 = true;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
		if (a[i] != i) f1 = false;
	}
	if (f1 == false)
	{
		sort(a + 1, a + n + 1);
		for (int i = 1; i < n; i++)
		{
			c[i] = a[i + 1] - a[i];
			sum[i] = sum[i - 1] + (i - 1) * c[i];
		}
		for (int i = 2; i <= n; i++)
		{
			bool f = false;
			for (int j = 1; j + i - 1 <= n; j++)
			{
				int val = sum[i + j - 2] - sum[j - 1];
//				cout << sum[i + j - 2] << ' ' << sum[j - 1] << '\n'; 
				if (val < m)
				{
					f = true;
				}
			}
			if (f)
			{
				ans = i;
			}
		}
		cout << ans;
	}
	else
	{
		int val = 0, i = 1;
		for (; val < m; i++)
		{
			val += i - 1;
		}
		if (val > m) cout << i - 3;
		if (val == m) cout << i - 2;
	}
	return 0;
} 
/*

               (\__
              (\   `\__
(`, .------.,-'     b  |
 `-/            ',__,-"` 
  |   `;      ,  |
   \   ;.----/ ,/
    ) // /  ( ( \
    \ \`.`\  \ \ \
     `-` `"   `-`"
*/ 
