#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LL long long

LL read(){LL x; scanf("%lld", &x); return x; }
//signed read(){
//	signed x = 0;
//	char c = getchar();
//	while(c < '0' || c > '9')c = getchar();
//	while('0' <= c && c <= '9')x = x * 10ll + (c - '0'), c = getchar();
//	return x;
//}

const int N = 15;

int n, k;
vector<int> e[N];

int ans;

int us[N];
int vs[N];
void dfs(int x){
	vs[x] = 1;
	for(int y : e[x])
		if(!vs[y] && us[y])dfs(y);
}
queue<int> q;
int dis[N];

void check(int s){
	int cp = 0, cb = 0;
	for(int i = 1; i <= n; i ++)us[i] = vs[i] = 0, dis[i] = n;
	
	for(int i = 1; i <= n; i ++)
		if(1 & (s >> (i - 1)))us[i] = 1, dis[i] = 0, cp ++;
	if(cp != k)return ;
	for(int i = 1; i <= n; i ++){
		if(!us[i])continue;
		if(vs[i])continue;
		dfs(i);
		cb ++;
		if(cb > 2)return ;
	}
	
	for(int i = 1; i <= n; i ++)
		if(us[i])q.push(i);
	while(q.size()){
		int x = q.front(); q.pop();
		for(int y : e[x])
			if(dis[y] > dis[x] + 1)dis[y] = dis[x] + 1, q.push(y);
	}
	int res = 0;
	for(int i = 1; i <= n; i ++)res = max(dis[i], res);
	
	ans = min(res, ans);
}

void solve(){
	for(int i = 1; i <= n; i ++)e[i].clear();
	n = read(); k = read();
	for(int i = 1; i < n; i ++){int u = read(), v = read(); e[u].push_back(v); e[v].push_back(u); }
	
	ans = n - 1;
	for(int s = 0; s < (1 << n); s ++)check(s);
	
	printf("%lld\n", ans);
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int cid = read(), tii = read();
	
	for(int z = 1; z <= tii; z ++)solve();
	
	
	
	return 0;
}
