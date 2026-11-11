#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans = 1,j = 1;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=2;i<=n;i++)
	{
		if (a[i] == a[i-1])
		{
			ans++;
		}
		else
		{
			b[j] = ans;
			j++;
			ans = 1;
		}
	}
	b[j] = ans;
	for (int i=1;i<=m;i++)
	{
		c[i] = b[i] + c[i-1];
		cout << c[i] << " ";
	}
	return 0;
}

