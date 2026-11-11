#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k[500005];
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> k[i];
	}
	for (int i=1; i<=m; i++)
	{
		if (i%4==1)
		{
			cout << m << " ";
		}
		else if (i%2==1)
		{
			cout << n << " ";
		}
		else
		{
			cout << k[1] << " ";
		}
	}
	return 0;
}
