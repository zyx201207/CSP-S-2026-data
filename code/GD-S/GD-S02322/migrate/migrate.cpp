#include <bits/stdc++.h>
using namespace std;
long long a, s[600000], g, d = 1, fg, bj, fd;
int main()
{
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin >> a >> g;
	for(int f = 1; f <= a; f++)
	{
		cin >> s[f];
	}
	sort(s + 1, s + a + 1);
	for(int f = 2; f <= a; f++)
	{
		fd = 1;
		fg = g;
		bj = f - 1;
		while(fg != 0)
		{
			if(bj >= 1 && fg > s[bj])
			{
				fg -= s[f] - s[bj];
				fd++;
				bj--;
			}
			else
			{
				break;
			}
		}
		d = max(d, fd);
	}
	cout << d;
	return 0;
} 
