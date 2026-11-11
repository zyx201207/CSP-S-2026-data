#include <bits/stdc++.h>
#define MAXN 1000006
using ll = long long;
using namespace std;
int n,k;
vector<int> vec[MAXN];
int mrk[MAXN];
int dis[111][111];
bool vis[MAXN];
void calc(int x){
	vis[x]=1;
	for(int j : vec[x])if(!vis[j] && mrk[j])calc(j);
}
void dfs(int x,int f,int rt){
	for(int j : vec[x]){
		if(j==f)continue;
		dis[rt][j] = dis[rt][x]+1;
		dfs(j,x,rt);
	}
}
int qwq(){
	int ans = 0;
	for(int i=1;i<=n;i++){
		int d = n;
		for(int j=1;j<=n;j++)if(mrk[j])d = min(d, dis[j][i]);
		ans = max(ans, d);
	}
	return ans;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		vec[i].clear();
		for(int j=1;j<=n;j++){
			dis[i][j] = 0;
		}
	}
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=1;i<=n;i++)dfs(i,0,i);
	int ans = n;
	for(int S=0;S<(1<<n);S++){
		if(__builtin_popcount(S) != k)continue;
		for(int i=0;i<n;i++)if((S>>i)&1)mrk[i+1] = 1; else mrk[i+1] = 0;
		for(int i=1;i<=n;i++)vis[i]=0;
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(mrk[i] && !vis[i])calc(i),cnt++;
		}
		if(cnt<=2)ans = min(ans,qwq());
	}
	cout<<ans<<"\n";
}
int main(){
#ifndef SVK
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int c,T; cin>>c>>T;
	while(T--)solve();
	return 0;
}


