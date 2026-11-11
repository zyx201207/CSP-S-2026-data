#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
ll c,t,n,id,k,u,v,ans,Inf=4e18;
ll vis[1000010],viss[1000010],dis[5010][5010];
vector<int> g[1000010];
void dfs(int x){
	viss[x]=1;
	for(auto v:g[x]){
		if(!viss[v]) dfs(v);
	}
	return;
}
void check(){
	ll cnt=0,cntk=0;
	rep(i,1,n) viss[i]=vis[i];
	rep(i,1,n){
		if(!viss[i]) cntk++,dfs(i);
		if(cntk>2) return;
	}
	rep(i,1,n){
		if(!vis[i]){
			ll w=Inf;
			rep(j,1,n){
				if(vis[j]) w=min(w,dis[i][j]);
			}
			cnt=max(cnt,w);
		}
	}
	ans=min(ans,cnt);
	return;
}
void dfs(int u,int cnt){
	if(cnt==k){
		check();
		return;
	}
	if(u==n+1) return;
	vis[u]=1;
	dfs(u+1,cnt+1);
	vis[u]=0;
	dfs(u+1,cnt);
	return;
}
void Dfs(int u,int f){
	for(auto v:g[u]){
		if(v==f) continue;
		dis[id][v]=dis[id][u]+1;
		Dfs(v,u);
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		rep(i,1,n-1){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		rep(i,1,n){
			id=i;
			Dfs(i,0);
		}
		ans=Inf;
		dfs(1,0);
		cout << ans << "\n";
		rep(i,1,n) g[i].clear();
	}
	return 0;
}
/*
4 3
1
2
3
5
666666666666666663
111111111111111105 
333333333333333326 
555555555555555547 
999999999999999989
*/
