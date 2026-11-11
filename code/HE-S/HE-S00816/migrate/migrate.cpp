#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int c,T,f[310][310],n;
ll d,x[N];
void solve()
{
	cin >> n >> d;
	for(int i = 1;i <= n;++ i) cin >> x[i];
	if(x[n] - x[1] <= d) {cout << "0\n";return;}
	if(c == 11 || c == 12)
	{
		ll s = x[2] - x[1];
		ll a = d / s;
		cout << max(0ll,n - 2 * a + 1) << "\n";
		return;
	}
	int cnt;
	if(c >= 1 && c <= 9 || n <= 300)
	{
		int ans = 0;
		for(int i = 1;i <= n;++ i) for(int j = 1;j <= n;++ j) f[i][j] = 2 * n;
		for(int i = 1;i <= n;++ i) f[i][i] = 0;
		for(int i = 1;i <= n;++ i) for(int j = i + 1;j <= n;++ j) if(x[j] - x[i] <= d) f[i][j] = 1;
		for(int len = 2;len <= n;++ len)
		{
			for(int i = 1;i <= n - len + 1;++ i)
			{
				cnt = 0;
				int j = i + len - 1;
				if(f[i][j] == 1) continue;
				for(int k = i;k < j;++ k)
				{
					if(x[k + 1] - x[k] > d) {f[i][j] = -1;break;}
				}
				if(f[i][j] == -1) {continue;}
				for(int k = i + 1;k < j;++ k)
				{
					if(f[i][k] == -1 || f[k][j] == -1) {cnt = 0;break;}
					if(f[i][k] + f[k][j] == f[i][j]) ++ cnt;
					if(f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k] + f[k][j],cnt = 1;
				}
				if(cnt == 2) ++ ans;
			}
		}
		cout << ans << "\n";
		return;
	}
	if(c == 13 || c == 14)
	{
		int s = 0,u = 0;
		for(int i = 1;i <= n;++ i) if(x[i] - x[1] <= d && x[n] - x[i] <= d){s = i,++ u;break;}
		if(u >= 2){cout << "0\n";return 0;}
		int f = s - 1,g = s + 1;
		for(int i = s - 1;i >= 1;-- i)
		{
			if(x[s + 1] - x[i] > d){f = i;break;}
		}
		for(int i = s + 1;i <= n;++ i)
		{
			if(x[i] - x[s - 1] <= d && x[i] - x[s - 2] > d){g = i;break;}
		}
		if(f != s - 1 && g != s + 1)
		{
			ans += f * (n - g + 1);
		}
		f = -1,g = -1;
		for(int i = s + 1;i <= n;++ i)
		{
			if(x[i] - x[s - 1] > d){f = i;break;}
		}
		for(int i = s - 1;i >= 1;-- i)
		{
			if(x[s + 1] - x[i] <= d && x[s + 2] - x[i] > d) {g = i;break;}
		}
		if(f != -1 && g != -1){ans += g * (n - f + 1);}
		cout << ans << "\n";
		return;
	}
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	while(T --) solve();
	return 0;
}

