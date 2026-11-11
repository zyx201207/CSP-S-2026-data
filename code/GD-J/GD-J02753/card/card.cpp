#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 100;
const int maxm = 5e3 + 100;

int n, m;
int a[maxn], cnt[maxm];
int tmp[maxn];
bool flag[maxn];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	for (int i = n; i >= 1; --i)
	{
		memset(tmp, 0, sizeof(tmp));
		memset(flag, 0, sizeof(flag));
		
		for (int j = 1; j <= i; ++j)
		{
			tmp[j] = a[j];
		}
		for (int j = 1; j <= i; ++j)
		{
			if (flag[tmp[j]])
			{
				for (int k = j; j >= 1; --k)
				{
					if (tmp[k] == tmp[j])
					{
						for (int l = k; l <= j; ++ l)
						{
							tmp[l] = 0;
							flag[l] = 0;
						}
					}
				}
			}
			else
			{
				flag[tmp[j]] = 1;
			}
		}
		
		for (int j = 1; j <= i; ++j)
		{
			if (!tmp[j]) cnt[tmp[j]] ++;
		}
	}
	
	for (int i = 1; i <= m; ++i)
	{
		cout << cnt[i] << " ";
	}
}
