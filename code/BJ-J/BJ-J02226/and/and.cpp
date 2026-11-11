#include <bits/stdc++.h>
using namespace std;
long long m,n,a[200005],ans = 0xfffffffffffffff,t[50],te[200005];
bool b[200005][35];
bool be[200005];
int cm[50];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		te[i] = a[i];
	for (int i = 1;i <= 30;i++)
		t[i] = (1<<(i-1));
	memset(be,1,sizeof be);
	for (int i = 1;i <= n;i++)
	{
		for (int j = 30;j >= 1 && te[i] != 0;j--)
		{
			if (te[i] >= t[j])
			{
				te[i] -= t[j];
				b[i][j] = 1;
				cm[j]++;
			}
		}
	}
	for (int j = 30;j >= 1;j--)
	{
		if (cm[j] >= m)
		{
			for (int i = 1;i <= n;i++)
			{
				if (b[i][j] == 1)
					be[i] &= 1;
				else
				{				
					te[i] = a[i];
					if (be[i] == 1)
					{
						for (int k = 30;k >= 1 && te[i] != 0;k--)
						{
							if (te[i] >= t[j])
							{
								te[i] -= t[j];
								b[i][j] = 0;
								cm[j]--;
							}
						}
					}
					be[i] = 0;
				}
			}
		}
	}
	for (int i = 1;i <= n;i++)
		if (be[i] == 1)
			ans &= a[i];
	cout << ans;
	return 0;
}

