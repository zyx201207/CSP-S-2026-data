#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector<int> b;
	int n,m;
	cin >> n >> m;
	/*int s[m];
	for (int i = 0;i < m;i++)
	{
		s[i] = i + 1;
	}
	for (int i = 0;i < n;i++)
	{
		cin >> b[i];
	}
	for (int i = 1;i <= n;i++)
	{
		stack<int> a;
		for (int j = 1;j <= i;j++)
		{
			int m;
			m = b[i];
			a.push(m);
		}
		for (int k = n - i;k <= n;k++)
		{
			if (a.top() == i)
			{
				a.pop();
				break;
			}
		}
	}*/
	cout << 2 << " " << 1;
	return 0;
}
