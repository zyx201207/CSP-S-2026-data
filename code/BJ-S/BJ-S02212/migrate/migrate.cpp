#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,anst,mi,ans;
long long x[2000005];
void f(int l,int r,int w)
{
	if (l >= r)
	{
		if (w < mi)
		{
			mi = w;
			anst = 1;
		}
		else if (w == mi)
			anst++;
		return;
	}
	for (int i = l;i <= r;i++)
	{
		if (x[i] - x[l] <= d)
			f(i,r,w+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		ans = 0;anst = 0;mi = 0;
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
			cin >> x[i];
		for (int i = 1;i <= n;i++)
		{
			for (int j = i;j <= n;j++)
			{
				f(i,j,0);
				if (anst == 2)
				{
					ans++;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
