#include <bits/stdc++.h>
using namespace std;

struct node
{
	long long num;
	char c;
}a[200010],b[200010];
long long n,len = 1,ans;

int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1;i <= n;i ++) cin >> a[i].num >> a[i].c;
	b[1] = a[1];
	for (int i = 2;i <= n;i ++)
		if (a[i].c == b[len].c) b[len].num += a[i].num;
		else b[++ len] = a[i];
	int l = 1,r = len;
	while (l < r)
	{
		long long x = b[l].num,y = b[r].num;
		long long num = 0;
		if (y >= x)
		{
			if (b[l].c == b[r].c)
			{
				b[r].num -= b[l].num;
				l ++,r --;
				continue;
			}
			else
			{
				ans += x;
				b[r].num -= b[l].num;
				l ++,r --;
				continue;
			}
		}
		while (y < x && l < r)
		{
			if (b[r].c == b[l].c)
				if (r == l + 1) 
					if (y + b[r].c >= x)
					{
						num += x - y;
						b[r].num -= x - y;
						break;
					}
					else
					{
						y += b[r].c;
						break;
					}
				else if (r > l + 1 && y + b[r - 1].num < x)
				{
					num += b[r].num;
					y += b[r].num;
				}
				else
				{
					b[r - 1].num -= x - y;
					num += y;
					y = x;
					break;
				}
			else
				if (r == l + 1) 
				{
					if (b[r].c == b[l].c) 
					{
						if (y + b[r].c >= x)
						{
							num += x - y;
							b[r].num -= x - y;
							break;
						}
						else
						{
							y += b[r].c;
							break;
						}
					}
					else
					{
						if (y + b[r].c >= x)
						{
							b[r].num -= x - y;
							break;
						}
						else
						{
							y += b[r].c;
							break;
						}
					}
				}
				else if (y + b[r - 1].num < x) y += b[r].num;
				else
				{
					if (b[r - 1].c == b[l].c) num += x - y;
					b[r - 1].num -= x - y;
					y = x;
					break;
				}
			r --;
		}
		if (y < x)
		{
			ans += y;
			continue;
		}
		//cout << y << " " << min(x , y - num) << "\n";
		ans += min(x , y - num);
		l ++;
	}
	cout << ans;
	return 0;
}