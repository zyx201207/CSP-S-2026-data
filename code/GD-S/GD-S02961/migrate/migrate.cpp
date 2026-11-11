#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		int n, d;
		cin >> n >> d;
		int a[n+5]={};
		for(int i=1;i<=n;i++) cin >> a[i];
		int x = a[3]-a[2];
		if(d%x == 0 && d/x>=2)
		{
			int y = 2*d-x;
			int sum = a[1] + y;
			cout << (a[n]-sum) / x + 1;
		}
		else if(d/x >= 2)
		{
			int y = (d/x) *2-1;
			int sum = a[1]+x*y;
			cout << (a[n]-sum) / x + 1;
		}
		else cout << 0;
	}
	return 0;
}
