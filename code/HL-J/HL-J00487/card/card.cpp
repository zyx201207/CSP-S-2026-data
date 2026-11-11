#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n + 5],s = 0;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		s += a[i];
		if(s >= 10)
		{
			cout << s;
		}
	}
	return 0;
}
