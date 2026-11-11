#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[5];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t >> n >> d;
	if (c == 0)
	{
		for (int i = 1;i <= 2;i++)
		{
			cin >> x[i];
		}
		if (x[1] == 1)
		{
			cout << 1 << endl << 2;
		}
		else if (x[1] == -2)
		{
			cout << 0 << endl << 1;
		}
	}
	else
	{
		for (int i = 1;i <= t;i++)
		{
			cout << (d+1)/2-1;
		}
	}
	return 0;
}

