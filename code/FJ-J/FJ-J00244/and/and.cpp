#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ans;
struct s
{
	int val,bit;
}a[200005];
bool cmp(s x,s y)
{
	if (x.bit == y.bit)
	{
		return x.val > y.val;
	}
	return x.bit > y.bit;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].val;
	}
	if (m == 1)
	{
		for (int i = 1;i <= n;i++)
		{
			ans = max(ans,a[i].val);
		}
	}
	else if (m == 2)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				ans = max(ans,a[i].val & a[j].val);
			}
		}
	}
	else if (m == n - 1)
	{
		for (int i = 1;i <= n;i++)
		{
			int tmp = 0x7fffffff;
		 	for (int j = 1;j <= n;j++)
		 	{
		 		if (j == i)
		 		{
		 			continue;
				}
				tmp &= a[j].val;
			}
			ans = max(tmp,ans);
		}
	}
	else if (m == n)
	{
		ans = 0x7fffffff;
		for (int i = 1;i <= n;i++)
		{
			ans &= a[i].val;
		}
	}
	else
	{
		ans = 0x7fffffff;
		for (int i = 1;i <= n;i++)
		{
			int t = a[i].val;
			while (t > 0)
			{
				if (t % 2 == 1)
				{
					a[i].bit++;
				}
				t /= 2;
			}
		}
		sort(a + 1,a + n + 1,cmp);
		for (int  i =1;i <= m;i++)
		{
			ans &= a[i].val;
		}
	}
	cout << ans;
	return 0;
}

