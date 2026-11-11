#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], maxn = -1, z = 0, ans = -1;
string DtoS(int n)
{
	string s;
	while(n > 0)
	{
		s += n % 2;
		n /= 2;
	}
	return s;
}
string Y(string x, string y)
{
	string s;
	for(int i = 0; i < max(x.size(), y.size()); i++)
	{
		if(x[i] == 1 && y[i] == 1)
		{
			s += '1';
		}
		else
		{
			s += '0';
		}
	}
}
int StoD(string s)
{
	int d;
	for(int i = 0; i < s.size(); i++)
	{
		d = d*2 + (s[i] - '0');
	}
	return d;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	
	
	
	if(m == 1)
	{
		cout << maxn << endl;
	}
	else if(m == n)
	{
		z = StoD(Y(DtoS(a[1]), DtoS(a[2])));
		for(int i = 3; i <= n; i++)
		{
			z += StoD(Y(DtoS(z), DtoS(a[2])));
		}
		cout << z << endl;
	}
	else if(m == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(j == i) continue;
				ans = max(ans, StoD(Y(DtoS(a[i]), DtoS(a[j]))));
			}
		}
		cout << ans*3 << endl;
	}
	return 0;
}

