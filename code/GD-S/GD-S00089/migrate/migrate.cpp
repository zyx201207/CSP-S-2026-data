#include<bits/stdc++.h>
using namespace std;


int a[2000005] = {};

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int i = 1;i <= t;i++)
	{
		int n;
		long long d;
		cin >> n >> d;
		for(int j = 1;j <= n;j++)
		{
			cin >> a[i];
		}
		cout << n - (d + 2) + 1 << endl;
	}
	return 0;
}
