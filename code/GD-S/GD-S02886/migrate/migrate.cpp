#include <bits/stdc++.h>
using namespace std;

long long x[2000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		int cha = x[2] - x[1];
		if(d / cha == 1) cout << 0 << endl;
		else
		{
			cout << n - 2 * (d / cha) + 1 << endl;
		}
	}        
	return 0;
}
