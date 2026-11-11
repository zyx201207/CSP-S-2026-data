#include<bits/stdc++.h>
using namespace std;
namespace IO {
	constexpr int bufsize = 230005;
	char buf[bufsize], *f1, *f2;
	char gtchar() {return f1 == f2 && (f2 = buf + fread(f1 = buf, 1, bufsize, stdin)) == buf? EOF: *f1++;}
	template<typename t> void read(t &ret)
	{
		int f = ret = 0;
		char ch = gtchar();
		while(!isdigit(ch)) f = ch == '-', ch = gtchar();
		while(isdigit(ch)) ret = ret * 10 + (ch ^ 48), ch = gtchar();
		if(f) ret = -ret;
	}
	template<typename t, typename ...T> void read(t &a, T &...b) {read(a), read(b...);}
} using IO::read;
constexpr int maxn = 1e6 + 5;
int testid, T, n, m;
int deg[maxn], dep[maxn], del[maxn], sz[maxn], son[maxn], flag[maxn];
vector<int> g[maxn], ng[maxn];
void dfs(int k, int pre)
{
	sz[k] = 1, son[k] = 0;
	for(int i : ng[k]) if(i != pre)
		dfs(i, k), sz[k] += sz[i], son[k] = i;
}
int calc(vector<int> vec, int mid)// 01  1...1
{
	int nn = vec.size();
	int ans = nn;
	vector<int> nxt(nn);
	for(int i = nn - 1; i >= 0; i--) nxt[i] = vec[i]? i: nxt[i + 1];
	for(int i = 0; i < nn - 1; i++)
	{
		int p = nxt[i + 1], tmp = i + 1 + (nn - p);
		if(p - i > 2 * mid + 1) tmp += p - i - 2 * mid - 1;
		ans = min(ans, tmp);
	}
	return ans;
}
bool check(int mid)// !!!!!!
{
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		deg[i] = g[i].size();
		if(deg[i] == 1) dep[i] = 1, q.push(i);
	}
	int cc = 0;
	fill(del + 1, del + 1 + n, 0);
	fill(flag + 1, flag + 1 + n, 0);
	while(q.size())
	{
		int t = q.front(); q.pop();
		++cc, del[t] = 1;
		if(dep[t] == mid) for(int i : g[t]) flag[i] = 1;
		else
		{
			for(int i : g[t]) if(--deg[i] == 1)
				dep[i] = dep[t] + 1, q.push(i);
		}
	}
	if(n - cc <= 2) return true;
	int rtmx = 0, rt = 0;
	for(int i = 1; i <= n; i++) if(!del[i])
	{
		ng[i].clear();
		for(int j : g[i]) if(!del[j]) ng[i].push_back(j);//, printf("%d->%d\n", i, j);
		if(rtmx < ng[i].size()) rtmx = ng[rt = i].size();
	}
	if(rtmx <= 2)
	{
		for(int i = 1; i <= n; i++) if(!del[i] && ng[i].size() == 1) rt = i;
		dfs(rt, 0);
		vector<int> vec;
		for(int i = rt; i; i = son[i]) vec.push_back(flag[i]);
		vec.front() = vec.back() = 1;
		return calc(vec, mid) <= m;
	}
	dfs(rt, 0);
	for(int i : ng[rt])
	{
		int now = i;
		vector<int> vec = {1, flag[i]};
		while(ng[now].size() == 2) now = son[now], vec.push_back(flag[now]);
		vec.back() = 1;
		if(calc(vec, mid) + (sz[now] - 1) + (sz[rt] - sz[i] - 1) <= m) return true;
	}
	return false;
}
void solve()
{
	read(n, m);
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1, x, y; i < n; i++)
	{
		read(x, y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(m == n) {puts("0"); return;}
	int l = 1, r = n;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	read(testid, T);
	while(T--) solve();
	return 0;
}