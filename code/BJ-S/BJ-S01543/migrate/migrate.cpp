#include <bits/stdc++.h>
using namespace std;
#define int long long

int c,t,a[2000005],dis[5005][5005],cnt[5005][5005];
int n,d;
void dfs(int x,int l,int r,int now)
{
	if (now > dis[l][r]) return;
	if (x == r)
	{
		if (dis[l][r] > now)
		{
			dis[l][r] = now;
			cnt[l][r] = 1;
			return;
		}
		if (dis[l][r] == now) cnt[l][r]++;
		return;
	}
	for (int i = x+1;i <= r;i++)
	{
		if (a[i]-a[x] <= d) dfs(i,l,r,now+1);
		else break;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		memset(dis,0x3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		cin >> n >> d;
		for (int i = 1;i <= n;i++) cin >> a[i];
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = i+1;j <= n;j++)
			{
				dfs(i,i,j,0);
				if (cnt[i][j] == 2) ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
