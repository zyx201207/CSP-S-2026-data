#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll ank[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> ank[i];
	}
	int l = 0, r = m - 1, ji;
	ll maxd = -1, nowd;
	while(r < n)
	{
		for(ji = l; ji <= r; ji++)
		{
			if(ji == l)
			{
				nowd = ank[l];
				continue;
			}
			nowd = nowd & ank[ji];
		}
		if(nowd > maxd)
		{
			maxd = nowd;
		}
		cout << nowd << maxd << "\n";
		nowd = 0;
		r++;
		l++;
	}
	cout << maxd << maxd << maxd;
	
	return 0;
}


