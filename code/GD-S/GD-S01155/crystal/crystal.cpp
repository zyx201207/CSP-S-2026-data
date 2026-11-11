#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
const int M = 100;
int n;
long long a[N], m;
int vis[210];
bool A = 1, B = 1, H = 1;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if(a[i] != i) A = 0;
		if(i > 2 && a[i]-a[i-1] != a[i-1] - a[i-2]) B = 0;
		if(a[i] > 100) H = 0;
	}
	sort(a+1, a+n+1);
	if(n <= 5000)
	{
		int ans = 0;
		for(int i = n; i >= 1; i--)
		{
			long long m1 = m;
			int ct = 0;
			for(int j = i; j >= 1; j--)
			{
				if(a[j] == a[i]) ct++;
				else if(a[i] - a[j] <= m1)
				{
					m1 -= a[i]-a[j];
					ct++;
				}
				else break;
			}
			ans = max(ans, ct);
		}
		cout << ans;
	}
	else if(A)
	{
		long long ct = 0;
		for(int i = 1; i <= n-1; i++)
		{
			ct += i;
			if(m < ct)
			{
				cout << i;
				break;
			}
		}
		if(m >= ct) cout << n;
	}
	else if(B)
	{
		long long ct = 0, gc = a[2]-a[1];
		for(int i = 1; i <= n-1; i++)
		{
			ct += i*gc;
			if(m < ct)
			{
				cout << i;
				break;
			}
		}
		if(m >= ct) cout << n;
	}
	else if(H)
	{
		long long ans = 0;
		for(int i = 1; i <= n; i++)
		{
			vis[a[i]+M]++;
		}
		for(int i = 1; i <= n; i++)
		{
			long long m1 = m, ct = 0;
			for(int j = a[i]; j >= -100; j--)
			{
				if(vis[j+M])
				{
					if(m1 >= vis[j+M] * (a[i] - j))
					{
						ct += vis[j+M];
						m1 -= vis[j+M] * (a[i] - j);
					}
					else
					{
						ct += m1 / (a[i] - j);
						break;
					}
				}
			}
			ans = max(ans, ct);
		}
		cout << ans;
	}
	return 0;
}
