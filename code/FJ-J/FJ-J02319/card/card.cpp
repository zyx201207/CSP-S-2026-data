#include<bits/stdc++.h>
using namespace std;
int a[500005], n, m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		cout << i << " ";
	}
	return 0;
}
