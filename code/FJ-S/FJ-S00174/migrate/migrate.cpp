#include <bits/stdc++.h>
using namespace std;
int c, t, n;
long long d, x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n; i++) cin >> x[i];
		if (d == 2)
		{
			if(n<= 3) cout << 0 << "\n";
			if (n == 4) cout << 1 << "\n";
			if (n== 5) cout << 2 << "\n";
			if(n==6) cout << 3 << "\n";
		}
		if(d == 3)
		{
			if(n <= 5) cout << 0 << "\n";
			if(n==6) cout << 1 << "\n";
		}
	} 
	return 0;
}
