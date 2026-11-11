#include <bits/stdc++.h>
using namespace std;
int f[20005][20005],a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = n;i >= 2;i--)
	{
		for(int j = 1;j <= i;j++)
		{
			a[j] = a[j + 1] | a[j] & a[j];
		}
	}
	cout << a[1];
	return 0;
}

