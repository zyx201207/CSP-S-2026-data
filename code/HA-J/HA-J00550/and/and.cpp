#include<bits/stdc++.h>
#define itn int
#define cotu cout
#define fro for
using namespace std;
int n,m,a[200005],maxn = 1,maxx = 1;
bool s[536870912];
bool myset(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,myset);
	maxx = a[1];
	for (int i = 2;i <= m;i++)
	{
		maxx = maxx & a[i];
	}
	int sum = 1,num = 1;
	bool x = 0;
	for (int i = 1;i <= n;i++)
	{
		if (s[a[i]] == 0)
		{
			if (x == 1)
			{
				x = 0;
				if (sum >= m)
				{
					maxn = max(maxn,num);
					break;
				}
				else
				{
					int w = m,t = num;
					for (int i = 1;i <= w-sum;i++)
					{
						if (a[i] == num)
						{
							w+=sum;
							i+=sum;
						}
						num = num & a[i];
					}
					maxn = max(maxn,num);
				}
			}
			s[a[i]] = 1;
		}
		else
		{
			num = a[i];
			sum++;
			x = 1;
		}
	}
	cout << max(maxx,maxn);
	return 0;
}

/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
