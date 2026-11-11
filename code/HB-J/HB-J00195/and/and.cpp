#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
//  check the freopen
//  &
int n,m,maxn = -1,a[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (m == 1)
	{
		for (int i = 1;i <= n;i++)
		{
			maxn = max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	if (m == 2)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (i == j)
				{
					continue;
				}
				int s = (a[i]&a[j]);
				maxn = max(maxn,s);
			}
		}
		cout << maxn;
		return 0;
	}
	sort(a+1,a+n+1);
	cout << a[n-m+1];
	
	return 0;
}
