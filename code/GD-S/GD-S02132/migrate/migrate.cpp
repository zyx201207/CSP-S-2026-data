#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef __int128 i128;
inline ll read(){
	ll x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
const int maxn = 2e6 + 5;
int c,t;
ll n,d,ans;
ll dist[maxn];
struct node{
	int depth,num;
}skip[5005][5005];
vector<int> g[maxn];
void dfs(int cur,int pre){
	if(cur > n) return ;
	node a = skip[pre][cur];
	int nxtdepth = a.depth + 1;
	for(int nxt : g[cur]){
		if(skip[cur][nxt].depth > nxtdepth){
			skip[cur][nxt].depth = nxtdepth;
			skip[cur][nxt].num = 1;
			dfs(nxt,cur);
		}else if(skip[cur][nxt].depth == nxtdepth){
			skip[cur][nxt].num++;
			dfs(nxt,cur);
		}
	}
	return ;
}
inline void solve1(){
	memset(skip,0,sizeof(skip));
	n = read(),d = read(),ans = 0;
	for(int i = 1;i <= n;i++){
		dist[i] = read();
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(dist[j] - dist[i] <= d){
				skip[i][j].depth = 1,skip[i][j].num = 1;
				g[i].push_back(j);
			}
		}
	}
	dfs(1,0);
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(skip[i][j].num == 2) ans++;
		}
	}
	printf("%lld\n",ans);
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(),t = read();
	if(c <= 10) while(t--) solve1();
	return 0;
}
