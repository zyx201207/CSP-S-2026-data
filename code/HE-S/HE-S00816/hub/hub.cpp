#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int c,T,n,k,dep[N],mx;
int head[N],to[N << 1],nxt[N << 1],las[N],sum[N],tot;
void add(int u,int v){
	to[tot] = v,nxt[tot] = head[u],head[u] = tot ++;
}
void dfs(int u,int fa)
{
	for(int i = head[u];~i;i = nxt[i])
	{
		int v = to[i];
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		las[v] = u;
		if(dep[v] > dep[mx]) mx = v;
		dfs(v,u);
	}
}

void dfs1(int u,int fa)
{
	for(int i = head[u];~i;i = nxt[i])
	{
		int v = to[i];
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		if(dep[v] == dep[mx] / 2) ++ sum[v];
		dfs(v,u);
		sum[u] += sum[v];
	}
}

void solve()
{
	cin >> n >> k;
	tot = 0;
	for(int i = 1;i <= n;++ i) head[i] = -1,sum[i] = 0;
	for(int i = 1,u,v;i <= n;++ i) cin >> u >> v,add(u,v),add(v,u);
	if(k == n) {cout << 0 << "\n";return;}
	if(c == 13 || c == 14)
	{
		int m = n / 2;
		if(k < 4){cout << m + 1 << "\n";return;}
		int cnt = m;
		while(k >= 4)
		{
			k -= 4;
			-- cnt;
		}
		cout << cnt << "\n";
		return;
	}
	for(int i = 1;i <= n;++ i) dep[i] = 0;
	dfs(1,0);
	for(int i = 1;i <= n;++ i) dep[i] = 0;
	int s = mx;
	dfs(s,0);s = mx;
	if(k == 1){cout << dep[mx] << "\n";return;}
	int x = dep[mx] / 2;
	while(x --) s = las[s];
	dfs1(s,0);
	ll cnt = 1;
	for(int i = head[s];~i;i = nxt[i]) cnt *= max(1,sum[to[i]]);
	if(cnt <= 2){cout << dep[mx] - 1 << "\n";}
	else cout << dep[mx] << "\n";
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	while(T --) solve();
	return 0;
}

