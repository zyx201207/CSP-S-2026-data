#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[1000005];
int cc[1000005];
int dis[1000005], cnt[1000005], to[1000005], from[1000005];
int lowbit(int x) {return x & (-x);}
int n;
void update(int pos, int val) {for(; pos <= n; pos += lowbit(pos)) cc[pos] += val;}
int query(int pos)
{
	int ret = 0;
	for(; pos; pos -= lowbit(pos)) ret += cc[pos];
	return ret;
}
int quer(int l, int r) {return query(r) - query(l - 1);}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, _;
	cin >> c >> _;
	while(_ --)
	{
		int d;
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) cin >> x[i];
		if(c >= 11 && c <= 12)
		{
			int len = x[2] - x[1], step = d / len;
			if(step <= 1) cout << 0 << endl;
			else cout << max(0ll, n - 2 * step + 1) << endl;
			continue;
		}
		if(c >= 13 && c <= 14)
		{
			int r = 0;
			x[n + 1] = 5e18;
			for(int i = 1; i <= n; i ++)
			{
				r = max(r, i);
				while(x[r + 1] - x[i] <= d) r ++;
				to[i] = r;
				if(!from[r]) from[r] = i;
			}
			for(int i = n; i >= 1; i --) if(!from[i]) from[i] = from[i + 1];
			if(to[1] < from[n] - 1) cout << 0 << endl;
			else
			{
				int L1 = 1, R1 = n;
				while(to[L1 + 1] <= to[1] + 1) L1 ++;
				while(from[R1 - 1] == from[n]) R1 --;
				int L2 = 1, R2 = n;
				while(to[L2 + 1] == to[1]) L2 ++;
				while(from[R2 - 1] >= from[n] - 1) R2 --;
				cout << (L1 - L2) * (R2 - R1) << endl;
			}
			continue;
		}
		int r = 0;
		x[n + 1] = 5e18;
		for(int i = 1; i <= n; i ++)
		{
			r = max(r, i);
			while(x[r + 1] - x[i] <= d) r ++;
			to[i] = r;
			if(!from[r]) from[r] = i;
		}
		for(int i = n; i >= 1; i --) if(!from[i]) from[i] = from[i + 1];
		int ans = 0;
		for(int i = 1; i <= n; i ++) dis[i] = 4e18;
		dis[1] = 0;
		cnt[1] = 1;
		for(int i = 1; i <= n; i ++)
		{
			update(i, cnt[i]);
			if(cnt[i] == 2) ans ++;
			for(int j = i + 1; j <= to[i]; j ++)
			{
				if(dis[j] == dis[i] + 1) cnt[j] += cnt[i];
				else if(dis[j] > dis[i] + 1) cnt[j] = cnt[i], dis[j] = dis[i] + 1;
			}
		}
		for(int i = 2; i <= n; i ++)
		{
			for(int j = i + 1; j <= to[i]; j ++)
			{
				if(dis[j] != 1)
				{
					dis[j] = cnt[j] = 1;
					int tmp = -quer(j, j);
					update(j, tmp + 1);
				}
			}
			int las = to[i];
			int flag = 0;
			for(int j = to[i] + 1; j <= n; j ++)
			{
				dis[j] = dis[from[j]] + 1;
				if(dis[j] != dis[las] + 1)
				{
					if(flag == j - 1 - las) break;
					las = j - 1, flag = 0;
				}
				cnt[j] = quer(from[j], las);
				int tmp = -quer(j, j);
				update(j, tmp + cnt[j]);
				if(cnt[j] > 2) flag ++;
				if(cnt[j] == 2) ans ++;
			}
		}
		cout << ans << endl;
		for(int i = 1; i <= n; i ++) cc[i] = from[i] = to[i] = 0;
	}
	return 0;
}
