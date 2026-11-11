#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10,INF = 0x3f3f3f3f3f3f3f3f;
int n,K;
struct edge{
	int to,nxt;
}e[N << 1];
int head[N],cnt_edge = 1;
void add_edge(int u,int v){
	e[++ cnt_edge] = {v,head[u]};
	head[u] = cnt_edge;
}
int len[N],cnt[N],root[N];
void dfs(int u,int fa){
	root[u] = u;
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].nxt;
		if(v == fa) continue;
		dfs(v,u);
		if(len[v] + 1 > len[u]){
			len[u] = len[v] + 1;
			cnt[u] = 1;
			root[u] = root[v];
		}else if(len[v] + 1 == len[u]){
			cnt[u] += cnt[v];
		}
	}
}
void solve(){
	cin >> n >> K;
	cnt_edge = 1;
	for(int i = 1;i <= n;i ++){
		head[i] = 0;
		len[i] = 0;
		cnt[i] = 1;
	} 
	for(int i = 1;i < n;i ++){
		int u,v;
		cin >> u >> v;
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	int c1 = cnt[1],x1 = len[1];
	int rt = root[1];
	for(int i = 1;i <= n;i ++){
		len[i] = 0;
		cnt[i] = 1;
	} 
	dfs(rt,0);
	int c2 = cnt[rt],x2 = len[rt];
	int y = x1 + x2;
	if(c1 == 1 || c2 == 1) y -= 2;
	else if(c1 <= 2 || c2 <= 2) y --;
	cout << y << '\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin >> c >> T;
	while(T --) solve();
	return 0;
}
