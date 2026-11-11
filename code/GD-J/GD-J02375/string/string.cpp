#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;
struct stu
{
	int x;
	char c;
 } a[200005], b[200005];
 long long qzh[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long len1 = 0, len = 0; 
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].c;
		b[i].x = a[i].x;
		qzh[i] = qzh[i - 1] + a[i].x; 
		b[i].c = a[i].c;
		len += a[i].x;
		len1 = len;
	}
	long long ans = 0, ans1 = 0;	
	if (len % 2)
	{
		for (int i = 1; i <= n; i++)
		{
			if (qzh[i - 1] < len / 2 + 1 && len / 2 + 1 <= qzh[i])
			{
				a[i].x--;	
				b[i].x--;
				len--;
				break;
			}
		}					
	}
	if (len % 2 == 0)
	{
		int i = 1, j = n;
		while(len >= 0 && i <= n)
		{
			len -= a[i].x;
			while (a[i].x == 0 && i <= n)
				i++;
			if (i > n)
				break;
			if (a[i].c == a[j].c)
			{
				if (a[i].x > a[j].x)
				{
					len -= a[i].x;
					int z = a[i].x - a[j].x;
					while(z)
					{
						j--;
						if (a[i].c == a[j].c)
						{
							if (a[j].x >= z)
							{
								a[j].x -= z;
								z = 0;
							}
							else
							{
								z -= a[j].x;
							}
						}
						else
						{
							if (a[j].x >= z)
							{
								a[j].x -= z;
								ans += z;
							}
							else
							{
								ans += z;
								a[j].x = 0;
							}
						}
					}	
				}
				else
				{
					len -= a[i].x;
					a[j].x -= a[i].x;
				}
			}
			else
			{
				if (a[i].x > a[j].x)
				{
					len -= a[i].x;
					ans += a[j].x;
					int z = a[i].x - a[j].x;
					while(z)
					{
						j--;
						if (a[i].c == a[j].c)
						{
							if (a[j].x >= z)
							{
								a[j].x -= z;
								z = 0;
							}
							else
							{
								z -= a[j].x;
							}
						}
						else
						{				
							
							if (a[j].x >= z)
							{
								a[j].x -= z;
								ans += z;
							}
							else
							{
								ans += z;
								a[j].x = 0;
							}
						}
					}	
				}
				else
				{
					ans += a[i].x;
					len -= a[i].x;
					a[j].x -= a[i].x;
				}
			}
			if (a[j].x == 0)
				j--;
			i++;	
		}
		i = n, j = 1;
		while(len1 >= 0 && i >= 1)
		{
			len1 -= b[i].x;
			if (b[i].c == b[j].c)
			{
				if (b[i].x > b[j].x)
				{
					len1 -= b[i].x;
					int z = b[i].x - b[j].x;
					while(z)
					{
						j++;
						if (b[i].c == b[j].c)
						{
							if (b[j].x >= z)
							{
								b[j].x -= z;
								z = 0;
							}
							else
							{
								z -= b[j].x;
							}
						}
						else
						{
							if (b[j].x >= z)
							{
								b[j].x -= z;
								ans1 += z;
							}
							else
							{
								ans1 += z;
								b[j].x = 0;
							}
						}
					}	
				}
				else
				{
					len1 -= b[i].x;
					b[j].x -= b[i].x;
				}
			}
			else
			{
				if (b[i].x > b[j].x)
				{
					len1 -= b[i].x;
					ans1 += b[j].x;
					int z = b[i].x - b[j].x;
					while(z)
					{
						j++;
						if (b[i].c == b[j].c)
						{
							if (b[j].x >= z)
							{
								b[j].x -= z;
								z = 0;
							}
							else
							{
								z -= b[j].x;
							}
						}
						else
						{
							if (b[j].x >= z)
							{
								b[j].x -= z;
								ans1 += z;
							}
							else
							{
								ans1 += z;
								b[j].x = 0;
							}
						}
					}	
				}
				else
				{
					ans1 += b[i].x;
					len1 -= b[i].x;
					b[j].x -= b[i].x;
				}
			}
			if (b[j].x == 0)
				j++;
			i--;	
		}					
	}
	cout << min(ans1, ans);
	return 0;
}
/*6 
1000000000 a 
1000000000 a 
1000000000 a 
1000000000 b 
1000000000 b 
1000000000 b 
*/
