#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e6 + 66;
int n, k, c, t, fa[N], ma[N], dist[N], rt, rt2;
pair<int, int> e[N];
vector<int> G[N];
set<pair<int, int> > s;
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
bool check(int nw)
{
	for(int i = 1;i <= n;i ++) fa[i] = i;
	int cnt = 0;
	for(int i = 0;i < n;i ++) if(nw & (1 << i)) cnt ++;
	if(cnt != k) return false;
	cnt = 0;
	for(int i = 1;i < n;i ++)
	{
		int x = e[i].first, y = e[i].second;
		if((nw & (1 << x - 1)) && (nw & (1 << y - 1))) fa[find(x)] = find(y);
	}
	for(int i = 0;i < n;i ++) if((nw & (1 << i)) && fa[i] == i) cnt ++;
	return cnt <= 2;
}
ll dfs(int nw, int x, int f)
{
	if((nw & (1 << x - 1)) && (x != f)) return -1;
	ll ans = 0;
	for(auto p : G[x]) if(p != f) ans = max(ans, dfs(nw, p, x) + 1);
	return ans; 
}
void dfs(int x, int fa)
{
	ma[x] = x;
	for(auto p : G[x])
	{
		if(p == fa) continue;
		dfs(p, x);
		if(dist[p] + 1 > dist[x]) ma[x] = ma[p];
		dist[x] = max(dist[x], dist[p] + 1);
	}
}
void dfs2(int x, int fa)
{
	int nxt = 0, mx = 0;
	for(auto p : G[x])
	{
		if(p == fa) continue;
		if(ma[p] == rt2) nxt = p;
		else mx = max(dist[p], mx);
	}
	dfs2(nxt, x);
	s.insert({mx, x});
}
int main()
{
	freopen("hub.in", "r", stdin);freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> k;ll ans = LLONG_MAX;
		for(int i = 1;i <= n;i ++) G[i].clear(), fa[i] = i;
		for(int i = 1;i < n;i ++)
		{
			int x, y;cin >> x >> y;
			G[x].push_back(y), G[y].push_back(x);
			e[i] = {x, y};
		}
		if(c == 7 || c == 11 || c == 12)
		{
			s.clear();
			dfs(1, 0);rt = ma[1];
			dfs(rt, 0);rt2 = ma[rt];
			dfs2(rt, 0);
			if(!s.empty())
			{
				int nw = 0;
				pair<int, int> p = *s.rbegin(), p2;
				s.erase(s.lower_bound(p));
				nw |= (1 << p.second - 1);
				if(!s.empty()) p2 = *s.rbegin(), nw |= (1 << p2.second - 1);
				ans = dfs(nw, rt, rt);
				cout << ans << '\n';
			}
			continue;
		}
		for(int i = 0;i < (1 << n);i ++)
			if(check(i))
			{
				ll cnt = 0;
				for(int j = 1;j <= n;j ++) cnt = max(cnt, dfs(i, j, j));
				ans = min(ans, cnt);
			}
		cout << ans << '\n';
	}
	return 0;
}
