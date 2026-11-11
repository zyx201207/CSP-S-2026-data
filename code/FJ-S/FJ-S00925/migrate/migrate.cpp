#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 5;

int kase;

int n; ll d,a[N];

vector<ll> f[N],g[N]; int nxt[N],lst[N];
void solve1()
{
	lst[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		lst[i] = lst[i - 1];
		while(a[i] - a[lst[i]] > d) lst[i]++;
	}
	nxt[n] = n;
	for(int i = n - 1; i >= 1; i--)
	{
		nxt[i] = nxt[i + 1];
		while(a[nxt[i]] - a[i] > d) nxt[i]--;
	}
	for(int i = 1; i <= n; i++)
		f[i].clear(),g[i].clear();
	for(int i = n; i >= 1; i--)
	{
		f[i].push_back(i);
		if(nxt[i] == i) continue;
		for(int j = 0; j < f[nxt[i]].size(); j++)
			f[i].push_back(f[nxt[i]][j]);
	}
	for(int i = 1; i <= n; i++)
		f[i].push_back(n + 1);
		
	for(int i = 1; i <= n; i++)
	{
		g[i].push_back(i);
		if(lst[i] == i) continue;
		for(int j = 0; j < g[lst[i]].size(); j++)
			g[i].push_back(g[lst[i]][j]);
	}
	for(int i = 1; i <= n; i++)
		g[i].push_back(0);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int k = 0;
		for(int j = i + 1; j <= n; j++)
		{
			while(k < f[i].size() && f[i][k] < j) k++;
//			cout << k << "\n";
			if(k == f[i].size()) break;
			int cnt = 0;
			for(int l = 0; l <= k - 1; l++)
				cnt += a[f[i][l]] + d > a[g[j][k - 1 - l]];
			ans += cnt == 2;
//			cout << i << " " << j << " " << cnt << "\n";
		}
	}
	cout << ans << "\n";	
}
void solve2()
{
	int p = 1,r = p;
	while(r < n && a[r + 1] - a[p] <= d) r++; p = r;
	while(r < n && a[r + 1] - a[p] <= d) r++; p = r;
	cout << n - p + 1 << "\n";
}
void solve()
{
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	if(kase <= 6) solve1();
	else(kase >= 11 && kase <= 12) solve2();
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> kase >> T;
	while(T--) solve();
	return 0;
}

