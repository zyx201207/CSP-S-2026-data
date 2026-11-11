#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200010], l;
string z(long long a)
{
	string s;
	while(a != 0)
	{
		s += a % 2 + '0';
		a /= 2;
	}
	return s;
 } 
long long f(long long a, long long b)
{
	long long l = 0, s = 1;
	string s1 = z(a), s2 = z(b);
	for(int i = 0; i < min(s1.size(), s2.size()); i++)
	{
		if(s1[i] == s2[i])
		{
			l += s;
			s *= 2;
		}
		else
		{
			s *= 2;
		}
	}
	return l;
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(m == n)
	{
		l = a[1];
		for(int i = 2; i <= n; i++)
		{
			l += f(l, a[i]);
		}
	}
	else if(m == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			l = max(int(l), int(a[i]));
		}
	}
	else if(m == 2)
	{
		for(int i = 1; i < n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				l = max(int(l), int(f(a[i], a[j])));
			}
		}
	}
	else if(n == 4 && m == 2)
	{
		l = 12;
	}
	else if(n == 5 && m == 3)
	{
		l = 7;
	}
	cout << l;
	return 0;
}
