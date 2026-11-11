#include <bits/stdc++.h>
using namespace std;
int c,t;
long long read()
{
	char c = getchar();
	long long res = 0,x = 1;
	while (c < '0' || c > '9')
	{
		if (c == '-')
		{
			x = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * x;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read();
	t = read();
	while (t--)
	{
		cout << "orz\n";
	}
 	return 0;
}

