#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[1] = a[i + 1]) ans++;
	}
	if(ans + 1 == n)
	{
		cout << m;
		return 0;
	}
	
	for(int i = 1; i <= n; i++)
	{
		int tmp = a[i] + a[i + 1];
		for(int j = 1; j <= n; j++)
		{
			if(j > n - 1)
			{
				if(a[i] + a[j + 1] == tmp) ans++;
			}
		}
		if(a[n - 1] + a[n] == tmp) ans++;
		if(ans == n)
		{
			cout << m / 2;
			return 0;
		}
	}
	return 0;
}
