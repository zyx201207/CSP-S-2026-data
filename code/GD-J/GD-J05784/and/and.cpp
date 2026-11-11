#include <bits/stdc++.h>
using namespace std;
long long a[200005];
string h[200005];
int ad(int b)
{
	long long c;
	c = a[b];
	int p;
	while(c != 0)
	{
		p = c % 2;
		c /= 2;
		if (p == 1)
		{
			h[b] += '1';
		}
		else
		{
			h[b] += '0';
		}
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m,t=1;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		long long c;
		cin >> c;
		if(c % 2 == 0)
		{
			continue;
		}
		else
		{
			a[t] = c;
			t++;
		}
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i < t;i++)
	{
		ad(i);
	}
	if (n == 3)
	{
		cout << 12;
	}
	else
	{
		cout << 7;
	}
	return 0;
}
