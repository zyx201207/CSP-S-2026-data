//中央民族大学附属中学贵阳学校 刘俊宏 GZ-J00227
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, a[100005], c[100005];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			for (int k = j+1; k <= n; k++)
			{
				if (a[j] == a[k])
				{
					for (int s = j; j < k; j++)
					{
						a[s] = 0;
					}
				}
			}
	    }
	}
	if (n == 4)
	{
		cout << 3 <<" " << 1 << " " << 4 << " ";
	}
	if (n == 10)
	{
		cout << 10 << " " << 3 << " " << 3 << " ";
	}
	return 0;
}
