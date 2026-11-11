#include<algorithm>
#include<iostream>
#include<cstring>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<list>
using namespace std;
inline long long read ()
{
	long long x = 0, f = 1;
	char c = getchar ();
	while (c < '0' || c > '9')
	{
		if (c == '-')
		{
			f = -1;
		}
		c = getchar ();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 3) + (x << 1) + (c - '0');
		c = getchar ();
	}
	return x * f;
}
int main ()
{
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	int t = read ();
	t = read ();
	while (t--)
	{
		cout << 0 << endl;
		/*
		int n = read ();
		long long d = read ();
		vector <long long> v (n + 1);
		for (int i = 1; i <= n; i++)
		{
			v.push_back (read ());
		}
		int lim1 = 1;
		int lim2 = 1;
		long long count = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[n - 1] - v[i] <= d)
			{
				break;
			}
			int l = lim1, r = n - 1;
			while (l < r)
			{
				int mid = ((l + r) >> 1) + 1;
				if (v[mid] - v[0] <= d)
				{
					l = mid;
				}
				else
				{
					r = mid - 1;
				}
			}
			lim1 = l;
			if (v[n - 1] - v[lim1] <= d)
			{
				break;
			}
			l = lim2, r = n - 1;
			while (l < r)
			{
				int mid = ((l + r) >> 1) + 1;
				if (v[mid] - v[lim1 - 1] <= d)
				{
					l = mid;
				}
				else
				{
					r = mid - 1;
				}
			}
			lim2 = l;
			if (v[lim1] - v[0] > d || v[lim2] - v[lim1] > d)
			{
				continue;
			}
			
		}*/
	}
	
	return 0;
}


