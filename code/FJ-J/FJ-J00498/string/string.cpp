#include <bits/stdc++.h>
using namespace std;

long long a[200005];
char c[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++)
		{
			s += c[i];
		}
	}
	int num = s.size() - 1;
	if (num % 2 == 0)
	{
		for (int i = 0; i <= s.size() / 2; i++)
		{
			if (s[i] != s[num--])
			{
				cnt++;
			}
		}
	}
	else
	{
		for (int i = 0; i <= s.size() / 2 - 1; i++)
		{
			if (s[i] != s[num--])
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
