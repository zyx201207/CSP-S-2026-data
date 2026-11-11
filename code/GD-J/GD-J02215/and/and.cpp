#include <bits/stdc++.h>
using namespace std;
#define long long int
const int N = 2e5 + 5;
int n, m, ans;
int a[N], f[N], use[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(m == 2)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				if(i == j) continue;
				f[i] = max(f[i], a[i] & a[j]);
			}
		for(int i = 1; i <= n; i++)
		{
			ans = max(ans, f[i]); 
		}
		cout << ans;
		return 0;
	}
	if(m == 1)
	{
		sort(a + 1, a + n + 1);
		cout << a[n];
		return 0;
	}
	if(m == n)
	{
		ans = a[1];
		for(int i = 2; i <= n; i++)
		{
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if(m == n - 1)
	{
		sort(a + 1, a + n + 1);
		ans = a[n];
		for(int i = n - 1; i >= 2; i--)
			ans &= a[i];
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1);
	bool flag = 0;
	for(int i = 1; i <= n; i++)
	{
		if((a[i] + 1) % 2 != 0)//B
		{
			flag = 1;
			break;
		}
	}
	cout << flag;
	if(flag)
	{
		ans = a[n];
		while(m--)
		{
			ans /= 2;
		}
		cout << ans;
	}
	else
	{
		cout << a[n - m + 1];
	}
	
	
	
}
