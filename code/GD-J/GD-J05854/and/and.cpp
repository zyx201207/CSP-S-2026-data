#include<iostream>
using namespace std;
int n, m, a[200005], bit[200005][35], ans[35], cnt[35], flag[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int p = 1;
		while (a[i])
		{
			bit[i][p] = a[i] % 2;
			a[i] /= 2;
			if(bit[i][p]==1)cnt[p]++;
			p++;
		}
	}
	int pos = 31;
	for (int i = 31; i >= 1; i--)
	{
		if (cnt[i] >= m)
		{
			pos = i;
			for (int j = 1; j <= n; j++)
			{
				if (bit[j][i] == 1) 
				{
					flag[j] = 1;
					//cout << j << ' ';
				}
			}
			break;
		}
	}
	for (int i = pos; i >= 1; i--)
	{
		int cnt1 = 0;
		for (int j = 1; j <= n; j++)
		{
			if (bit[j][i] == 1 && flag[j] == 1)cnt1++;
		}
		if (cnt1 >= m)
		{
			ans[i] = 1;
			for (int j = 1; j <= n; j++)
			{
				if (bit[j][i] == 0)flag[j] = 0;
			}
		}
		//cout << cnt1 << ' ';
	}
	int ans1 = 0;
	for (int i = 1; i <= pos; i++)
	{
		ans1 += (ans[i] << (i - 1));
	}
	cout << ans1;
	return 0;
}
