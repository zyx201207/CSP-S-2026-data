#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],ma[300005];
string s;

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
		for (int j = i; j <= n; j++)
		{
			s += a[j];
			if (i == j) continue;
			for (int z = 0; z < s.length(); z++)
			{
				if (s[z] == a[j])
				{
					cout << endl;
					for (int y = z; y < s.length(); y++)
					{
						s[y] -= s[y];
					} 
					s[s.length()-1] = a[j];
				}
			}
		}
		for (int j = 0; j < s.length(); j++)
		{
			//cout << int(s[j]);
			ma[int(s[j])]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ma[m] << " ";
	}
} 
