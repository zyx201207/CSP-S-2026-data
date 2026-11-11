#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005],st[2000005],ed[2000005],l[2000005],r[2000005],f[2000005],g[2000005];
void init()
{
	for(int i = 1; i <= n; i++) f[i] = g[i] = st[i] = ed[i] = 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		init();
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		int cur_l = 1,cur_r = 1;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			while(x[i] - x[cur_l] > d) cur_l++;
			while(cur_r < n && x[cur_r+1] - x[i] <= d) cur_r++;
			l[i] = cur_l,r[i] = cur_r;
//			cout << l[i] << " " << r[i] << endl;
		}
//		cout << endl;
		for(int i = 1; i <= n; i++)
		{
			if(r[i] > i) st[r[i]]++;
			if(l[i] < i) ed[l[i]]++;
		}
		for(int i = 1; i <= n; i++)
		{
			f[i] = st[i];
			if(r[l[i]] == i) f[i] += f[l[i]];
		}
		for(int i = n; i >= 1; i--)
		{
			g[i] = ed[i];
			if(l[r[i]] == i) g[i] += g[r[i]];
		}
		for(int i = 1; i < n; i++)
		{
			bool flag1 = (l[i] == l[i+1] && r[l[i+1]] == i+1),flag2 = (r[i] == r[i+1] && l[r[i]] == i);
//			cout << flag1 << " " << flag2 << endl;
//			cout << f[i+1] << " " << st[i+1] << " " << g[i] << " " << ed[i] << endl;
			if(flag1)
			{
				ans += (f[i+1] - st[i+1]) * (ed[i] - (l[i+1] == i));
			}
			if(flag2)
			{
				ans += (st[i+1] - (r[i] == i+1)) * (g[i] - ed[i]);
			}
			if(flag1 && flag2)
			{
				ans += (f[i+1] - st[i+1]) * (g[i] - ed[i]);
			}
			ans += (st[i+1] - (r[i] == i+1)) * (ed[i] - (l[i+1] == i));
		}
		cout << ans << '\n';
	}
	return 0;
}
