#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
long long a[200010],maxn = -1e9;
bool vis[200010];

bool cmp(int x,int y)
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
	if (m == 1)
	{
		sort(a+1,a+n+1);
		cout << a[n] << endl;
	}
	else if (m == 2)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = i+1;j <= n;j++)
			{
				maxn = max(maxn,a[i]&a[j]);
			}
		}
		cout << maxn << endl;
	}
	else if (m == n)
	{
		long long sum = a[1];
		for (int i = 2;i <= n;i++)
		{
			sum = sum&a[i];
		}
		cout << sum << endl;
	}
	else if (m == n-1)
	{
		sort(a+1,a+n+1);
		long long sum = a[2];
		for (int i = 3;i <= n;i++)
		{
			sum = sum&a[i];
		}
		cout << sum << endl;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		long long sum = a[1];
		for (int i = 2;i <= m;i++)
		{
			sum = sum&a[i];
		}
		cout << sum << endl;
	}
	return 0;
}
