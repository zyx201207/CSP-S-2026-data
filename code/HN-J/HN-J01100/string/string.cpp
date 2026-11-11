#include <bits/stdc++.h>
using namespace std;
int n;
long long x,y,a[200005],cnt = 0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	int pos1 = 1,pos2 = n,x = a[1],y = a[n];
	while (pos1 < pos2 - 1)
	{
		if (x >= y)
		{
			if (c[pos1] != c[pos2]) cnt += y;
			x -= y;
			pos2--;
			y = a[pos2];
		}
		else
		{
			if (c[pos1] != c[pos2]) cnt += x;
			y -= x;
			pos1++;
			x = a[pos1];
		}
	}
	if (x >= y)
	{
		if (c[pos1] != c[pos2]) cnt += y;
		x -= y;
		y = 0;
	}
	else
	{
		if (c[pos1] != c[pos2]) cnt += x;
		y -= x;
		x = 0;
	}
	cout << cnt;
	return 0;
}
