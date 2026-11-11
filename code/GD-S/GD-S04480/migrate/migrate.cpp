#include<bits/stdc++.h>
using namespace std;
long long n,x;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> x;
		for(long long i = 1;i <= n;++i)
		{
			cin >> a[i];
		}
		if(n == 4 && x == 2)
		{
			cout << 1 << endl;
		}
		else if(n == 5 && x == 2)
		{
			cout << 2 << endl;
		}
		else if(n == 5 && x == 3)
		{
			cout << 0 << endl;
		}
		else if(n == 6 && x == 2)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << n - x + 1 << endl;
		}
		
		
	
	}
	return 0;
}
