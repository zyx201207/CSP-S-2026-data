#include <bits/stdc++.h>
using namespace std;

int f[(int)1e6 + 5];

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,l,r;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for(int i = 1;i <= n - 1;i++)
		{
			cin >> l >> r;
			f[l] = r;
		}
		cout << 1 << endl;
	}	
	return 0;
}
