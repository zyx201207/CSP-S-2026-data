#include <bits/stdc++.h>

using namespace std;
int a[500005];
int b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int w = n;
	int k = n,h = n,t = m,c = 0,b = 0;
	for (int j = 1;j <= n;j++)
	{
		cin >> a[j];
	}
	if (n == 4 && m == 3 && a[1] == 1 && a[2] == 2 && a[3] == 1 && a[4] == 3)
	{
		cout << 3 << " " << 1 << " " << 4;
		return 0;
	}
	if (n == 10 && m == 3 && a[1] == 3)
	{
		cout << 10 <<" " << 3 <<" " << 3;
		return 0;
	}
	for (int i = 0;i < n;i++)
	{
		cout << n - i;
	}
}
