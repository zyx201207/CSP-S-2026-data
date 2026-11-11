#include <bits/stdc++.h>
using namespace std;
struct inp
{
	long long a;
	char c;
};
inp s[100000005];
long long n, cnt, l, r; 
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].a >> s[i].c;
	}
	l = 1; r = n;
	while (l < r)
	{
		if (s[l].c != s[r].c)
		{
			cnt += min(s[l].a, s[r].a);
			if (s[l].a < s[r].a)
			{
				s[r].a -= s[l].a;
				s[l].a = 0;
				l ++;
			}
			else if (s[l].a == s[r].a)
			{
				l ++;
				r --;
			}
			else
			{
				s[l].a -= s[r].a;
				s[r].a = 0;
				r --;
			}
		}
		else
		{
			if (s[l].a < s[r].a)
			{
				s[r].a -= s[l].a;
				s[l].a = 0;
				l ++;
			}
			else if (s[l].a == s[r].a)
			{
				l ++;
				r --;
			}
			else
			{
				s[l].a -= s[r].a;
				s[r].a = 0;
				r --;
			}
		}
	}
	printf("%lld\n", cnt);
	return 0;
} 
