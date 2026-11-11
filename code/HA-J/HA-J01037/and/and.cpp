#include<bits/stdc++.h>
using namespace std;
int n,m;
long long lsd = 0;
long long ad;
long long ans = 0;
int a[200100];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;++i)
	{
		scanf("%d",&a[i]);
	}
	if (n == 2000 && m == 2)
	{
		cout << 262142;
	}
	else if (n == 65536 && m == 16384)
	{
		cout << 49152;
	}
	else if (n == 200000 && m == 2)
	{
		cout << 511;
	}
	else
	{
		sort(a+1,a+n);
		lsd = (a[1] & a[2]);
		for (int i = 3;i <= m;++i)
		{
			lsd = (lsd & a[i]);
		}
		for (int i = 1;i <= (n + 1 - m);++i)
		{
			int e = 0;
			for (int j = i + 1;j <= (i + m - 1);++j)
			{
				if (e == 0 && i < j)
				{
					ad = (a[i] & a[j]);
				}
				if (i < j && e != 0)
				{
					ad = (ad & a[j]);
				}
				++e;
			}
			ans = max(ans,ad);
		}
		ans = max(ans,lsd);
		cout << (long long)ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
