#include <bits/stdc++.h>
using namespace std;
#define ms(a, b) memset(a, b, sizeof(a));
const int maxn = 5e5;

int n, m, q, c, d;
int w[maxn], k;
vector<pair<int, int>> a[505];
int x, y;
int ljb[505][505]; 
int ptr[505];
int lwb(int fd, int u)
{
	int l = 0, r = a[u].size() - 1, mid, ans;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(a[u][mid].first <= fd)
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

long long slove()
{
	cin >> x >> y;
	long long f[505];
	bool vis[505];
	ms(f, 0x3f)
	ms(vis, 0)
	for(int i = 1;i <= n;i++)
	{
		int lb = lwb(x, i);
//		cout << lwb(x, i) << " " << a[i][lwb(x, i)].first << endl;
		if(a[i][lb].first == x)
		{
			f[i] = a[i][lb].second;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		int minn = 0;
		for(int j = 0;j <= n;j++)
		{
			if(!vis[j] && f[minn] > f[j]) minn = j;
		}
		for(int j = 1;j <= n;j++)
		{
			if(j == minn || vis[j]) continue;
			f[j] = min(min(f[minn] + ljb[j][minn], 0x3f3f3f3f3f3f3f3f), f[j]);
		}
	}
	long long ans = LLONG_MAX;
	for(int i = 1;i <= n;i++)
	{
		int lb = lwb(y, i);
		if(a[i][lb].first == y)
		{
			ans = min(f[i] + a[i][lb].second, ans);
		}
	}
	return ans;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m;i++)
	{
		scanf("%d", &w[i]);
	}
	for(int i = 1;i <= n;i++)
	{
//		cin >> k;
		scanf("%d", &k);
		while(k--)
		{
			int qwq, qaq;
			scanf("%d %d", &qwq, &qaq);
			a[i].push_back({qwq, qaq});
		}
		sort(a[i].begin(), a[i].end());
		ms(ljb, 0x3f) 
	}
	for(int st = 1;st <= m;st++)
	{
		vector<int> ith;
		for(int sb = 1;sb <= n;sb++)
		{
			if(ptr[sb] == st)
			{
				sb++;
				ith.push_back(sb);
			}
		}
		for(int ui = 0;ui < ith.size();ui++)
		{
			for(int vi = 0;vi < ui;vi++)
			{
				int u = ith[ui], v = ith[vi];
				ljb[u][v] = ljb[v][u] = min(ljb[u][v], a[u][ptr[u] - 1].second + a[v][ptr[v] - 1].second);
			}
		}
	}
	while(q--)
	{
		printf("%lld\n", slove());
	}
	return 0;
 } 
 //第四次重构了，还78输出INF。不管你了，自己一边玩儿去吧。 
 //害我T3T4都没开，出题组真毒瘤。 
