#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,s,r,x;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> d;
		cin >> s >> x;
		r = x - s;
		for(int i = 1;i <= n - 2;i ++) cin >> x;
		x = d / r;
		if(x <= 1) cout << 0 << endl;
		else cout << max(n + 1 - 2 * x,0ll) << endl;
	}
}
