#include <bits/stdc++.h>
using namespace std;
int a,b,f[100005],cnt;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> a >>b;
	for (int i = 1;i <= a;i++)
	{
		cin >> f[i];
	}
	for (int i = 1;i <= a;i++)
	{
		for (int j = 1;j <= a;j++)
		{
			cnt = amx(cnt,(i & j));
		}
	}
	cout << cnt
	return 0;
}