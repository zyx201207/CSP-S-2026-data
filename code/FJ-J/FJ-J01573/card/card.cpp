#include <bits/stdc++.h>
using namespace std;
stack<int> c;
int n, m, a[500005], t[300005], f[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		while(!c.empty())
		{
			c.pop();
		}
		memset(f, 0, sizeof(f));
		for (int j = i; j <= n; j++)
		{
			t[a[j]]++;
			if(!f[a[j]])
			{
				c.push(a[j]);
				f[a[j]]++;
			}
			else
			{
				//cout << c.top() << " " << a[i] << endl;
				while(c.top() != a[j])
				{
					f[c.top()]--;
					t[c.top()]--;
					c.pop();
				}
				t[a[j]]--;
				//c.push(a[i]);
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << t[i] << " ";
	}
}
