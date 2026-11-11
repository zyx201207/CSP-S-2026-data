#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int n, m, a[2005], ma = 0;
int main()
{
	freopen("and.in","r" ,stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if (m == 1)
	{
		for (int i = 0;i < n;i++)
		{
			ma = max(ma, a[i]);
		}
		cout << ma << endl;
	}
	else if (m == 2)
	{
		for (int i = 0;i < n;i++)
		{
			for (int j = i + 1;j < n;j++)
			{
				ma = max(ma, a[i] % a[j]);
			}
		}
		cout << ma << endl;
	}
	return 0;
}
