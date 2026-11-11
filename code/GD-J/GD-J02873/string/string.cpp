#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long num[200002],ans =0;
	char a[200002];
	cin >> n;
	for (int i = 1;  i <= n ; i ++)
	{
		cin >> num[i];
		cin >> a[i];
	}
	int k = n ;
	int s = 1;
	while (s <= k)
	{
		if (a[s] != a[k])
		{
			if (num[s] < num[k])
			{
				ans += num[s];
			}
			else if (num[s] < num[k])
			{
				ans += num[k];
			}
			else
			{
				ans += num[s];
			}
		}
		if (num[s] < num[k])
		{
			num[k] -= num[s];
			s ++;
		}
		else if (num[s] < num[k])
		{
			num[s] -= num[k];
			k --;
		}
		else
		{
			s ++;
			k --;
		}
	}
	cout << ans;
	return 0;
}
