#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> f[1000005];
int c,t,n,k,ans = 1e18;
bool ch[1000005];
int col[1000005];
int dis[1000005];

void paint(int now,int color){
	for(auto nxt : f[now])
		if(ch[nxt] && col[nxt] == 0)
			col[nxt] = color,paint(nxt,color);
	return;
}
void tmp(int now,int father,int dist,int root){
	if(ch[now]){
		dis[root] = min(dis[root],dist);
		return;
	}
	for(auto nxt : f[now])
		if(nxt != father)
			tmp(nxt,now,dist + 1,root);
	return;
}
void solve(){
	for(int i = 1;i <= n;++i){
		dis[i] = 1e10;
		tmp(i,0,0,i);
	}
	int maxn = 0;
	for(int i = 1;i <= n;++i)
		maxn = max(maxn,dis[i]);
	ans = min(ans,maxn);
	return;
}
int check(){
	memset(col,0,sizeof(col));
	int flag = 0;
	for(int i = 1;i <= n;++i){
		if(ch[i] && col[i] == 0)
			paint(i,++flag);
	}
	return flag;
}
void dfs(int step,int choose){
	if(choose > k) return; 
	if(step > n){
		if(check() <= 2)
			solve();
		return;
	}
	ch[step] = true;
	dfs(step + 1,choose + 1);
	ch[step] = false;
	dfs(step + 1,choose);
	return;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	for(int _ = 1;_ <= t;++_){
		scanf("%lld %lld",&n,&k);
		ans = 1e18;
		for(int i = 1;i <= n;++i)
			f[i].clear();
		for(int i = 1;i < n;++i){
			int u,v; scanf("%lld %lld",&u,&v);
			f[u].push_back(v);
			f[v].push_back(u); 
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}

