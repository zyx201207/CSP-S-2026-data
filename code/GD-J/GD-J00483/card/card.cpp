#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[(int)5e5 + 5];
int b[(int)5e5 + 5];
int v[(int)5e5 + 5];
int ans[(int)5e5 + 5];

int f(int x)
{
	memset(b,0,sizeof b);
	int cnt = 0;
	for(int i = x;i <= n;i++)
	{
		if (b[a[i]] <= cnt && b[a[i]] != 0)
		{
			cnt = b[a[i]];
		}
		else
		{
			v[++cnt] = a[i];
			b[a[i]] = cnt;
		}
//		printf("%d\n",cnt);
	}
	for(int i = 1;i <= cnt;i++)
	{
//		cout << v[i] << " ";
		ans[v[i]]++;
	}
//	cout << endl;
	return 0;
}

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	int flag = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i]; 
		if (a[i - 1] > a[i])
		{
			flag = 0;
		}
	}
	if (n <= 5000 && m <= 3000)
	{
		for(int i = 1;i <= n;i++)
		{
			f(i);
		}
		for(int i = 1;i <= m;i++)
		{
			cout << ans[i] << " ";
		}
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		b[a[i]]++;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			ans[j] += b[j] % 2; 
		}
		b[a[i]]--;
	}
	for(int i = 1;i <= n;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
} 

/*
4 3
1 2 1 3

*/

