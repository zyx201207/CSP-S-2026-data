#include <bits/stdc++.h>
using namespace std;

long long w[500005];
struct node
{
	long long p, t;
	bool operator <(const node &x) const
	{
		return x.t < t;
	}
};
vector<node> v[501005];
long long dis[501005];
long long cnt[501005];
long long len[500005][3];
bool vis[501005];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long c, n, m, d, qu;
	cin >> c >> n >> m >> d >> qu;
	for(long long i = 1; i <= m; i++) cin >> w[i];
	long long t;
	long long minn = 1e9;
	for(long long i = 1; i <= n; i++)
	{
		long long k;
		cin >> k;
		for(long long j = 1; j <= k; j++) 
		{
			long long x, y;
			cin >> x >> y;
			t = y;
			v[m + i].push_back(node{x, y});
			v[x].push_back(node{m + i, y});
			cnt[x] += i;
			if(c == 20 || c == 21) len[x][i] = y;
			if((c == 20 || c == 21) && cnt[x] == 3) minn = min(minn, len[x][1] + len[x][2]);
		}
	}
	if(12 <= c && c <= 19)
	{
		while(qu--)
		{
			long long x, y;
			cin >> x >> y;
			queue<long long> q;
			q.push(x);
			memset(dis, 0, sizeof(dis));
			dis[x] = 0;
			while(!q.empty())
			{
				long long x = q.front();
				q.pop();
				for(long long i = 0; i < v[x].size(); i++)
				{
					long long y = v[x][i].p;
					if(!dis[y])
					{
						dis[y] = dis[x] + 1;
						q.push(y);
					}
				}
			}
			cout << w[x] + w[y] + dis[y] * t << "\n";
		}
	}
	else if(c == 20 || c == 21)
	{
		while(qu--)
		{
			int x, y;
			cin >> x >> y;
			long long ans = 0;
			if((cnt[x] == 1 && cnt[y] == 1) || (cnt[x] == 2 && cnt[y] == 2))
			{
				ans += len[x][cnt[x]] + len[y][cnt[y]] + w[x] + w[y];
			}
			if((cnt[x] == 1 && cnt[y] == 2) || (cnt[x] == 2 && cnt[y] == 1))
			{
				ans += len[x][cnt[x]] + len[y][cnt[y]] + w[x] + w[y] + minn;
			}
			if((cnt[x] == 3 && (cnt[y] == 1 || cnt[y] == 2)))
			{
				ans += len[x][cnt[y]] + len[y][cnt[y]] + w[x] + w[y];
			}
			if(((cnt[x] == 1 || cnt[x] == 2) && cnt[y] == 3))
			{
				ans += len[x][cnt[x]] + len[y][cnt[x]] + w[x] + w[y];
			}
			if(cnt[x] == 3 && cnt[y] == 3)
			{
				ans = min(len[x][1] + len[y][1], len[x][2] + len[y][2]);
				ans += w[x] + w[y];
			}
			cout << ans << "\n";
		}
	}
	else
	{
		while(qu--)
		{
			int x, y;
			cin >> x >> y;
			priority_queue<node> q;
			q.push(node{x, 0});
			memset(dis, 0x3f, sizeof(dis));
			memset(vis, 0, sizeof(vis));
			dis[x] = 0;
			while(!q.empty())
			{
				node k = q.top();
				q.pop();
				if(vis[k.p]) continue;
				vis[k.p] = 1;
				for(int i = 0; i < v[k.p].size(); i++)
				{
					int y = v[k.p][i].p;
					if(dis[y] >= dis[k.p] + v[k.p][i].t) 
					{
						dis[y] = dis[k.p] + v[k.p][i].t;
						q.push(node{y, dis[y]});
					}
				}
			}
			cout << dis[y] + w[x] + w[y] << "\n";
		}
	}
	return 0;
}
