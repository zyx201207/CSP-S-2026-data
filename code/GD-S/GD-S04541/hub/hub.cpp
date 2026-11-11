#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int n,ans,k,f[N],dis[N];
queue<int> q;
vector <int> G[N];
void check(){
	for (int i=1;i<=n;i++) 
		if (f[i]){
			q.push(i);
			dis[i]=0;
		}
		else dis[i]=1e18;
	while (!q.empty()){
		int x=q.front();
		q.pop();
		for (int i=0;i<G[x].size();i++){
			int y=G[x][i];
			if (dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				q.push(y);
			}
		}
	}
	int res=0;
	for (int i=1;i<=n;i++) res=max(res,dis[i]);
	ans=min(res,ans);
	return ;
}
void dfss(int x,int cnt,int id){
	if (cnt>=k){
		check();
		return ;
	}
	for (int i=0;i<G[x].size();i++){
		int y=G[x][i];
		if (y>id){
			f[y]=1;
			dfss(y,cnt+1,id);
			f[y]=0;
		}
	}
}
void dfs(int x,int cnt,int id){
	if (cnt+1<=k){
		for (int i=id+1;i<=n;i++) if (f[i]==0) {
			f[i]=1;
			dfss(i,cnt+1,id);
			f[i]=0;
		}
	}
	else return ;
	for (int i=0;i<G[x].size();i++){
		int y=G[x][i];
		if (y>id){
			f[y]=1;
			dfs(y,cnt+1,id);
			f[y]=0;
		}
	}
	return ;
}
void init(){
	ans=1e18;
	for (int i=1;i<=n;i++) G[i].clear();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int ID,T;
	scanf ("%lld%lld",&ID,&T);
	while (T--){
		scanf ("%lld%lld",&n,&k);
		init();
		for (int i=1;i<n;i++){
			int u,v;
			scanf ("%lld%lld",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if (k>=n){
			puts("0");
			continue;
		}
		for (int i=1;i<=n;i++){
			f[i]=1;
			if (k>1) dfs(i,1,i);
			if (k==1) dfss(i,1,i);
			f[i]=0;
		}
		printf ("%lld\n",ans);
	}
	return 0;
}

