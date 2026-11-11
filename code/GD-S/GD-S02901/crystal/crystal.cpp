#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long m;
	cin >> n >> m;
	int a[n + 5];
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int max = -1;
	for (int i = 1;i < n;i++)
	{
		int c = 1;
		while(m > 0)
		{
			
				m = m - a[i] - a[i - c];
				c++;
			
		}
		if (max < c)
		{
			max = c;
		}
	}
	cout << max;
	return 0;
}
