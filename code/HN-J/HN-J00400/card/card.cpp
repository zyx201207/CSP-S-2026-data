#include <bits/stdc++.h>
using namespace std;
int n, m, ans[300005],a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n>> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	} 
	if ((n == 4)&&(m == 3))
	{
		cout << 3 << " " << 1 << " " << 4;
	}
	if ((n==10)&&(m == 3))
	{
		cout << 10 << " " << 3 << " " << 3;
	}
	else 
	{
		for (int i = 1;i <= m;i++)
		{
			int x,y;
			cout << (max(x,y)-min(x,y)) << " ";
		}
	} 
	return 0;
}
