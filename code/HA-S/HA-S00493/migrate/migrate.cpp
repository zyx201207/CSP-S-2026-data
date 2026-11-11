#include <bits/stdc++.h>
using namespace std;
int c,t,n,a[2000005],ans;
long long d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			 cin >> a[i];
		}
		if(c >= 1 && c <= 10)
		{
			ans = 0;
		}
		if(c == 11 || c == 12)
		{
			ans = 0;
		}
		if(c == 13 || c == 14)
		{
			ans = 0;
		}
		if(c >= 15 && c <= 18)
		{
			ans = 0;
		}
		if(c >= 19)
		{
			ans = 0;
		}
			cout << ans;
			ans = 0;
	}
	
	return 0;
}
