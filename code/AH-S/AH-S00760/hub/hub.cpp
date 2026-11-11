#include<bits/stdc++.h>
using namespace std;
const int N=1e6+4;
int c,t,n,k;
vector<int>g[N];
int vis[N],ans;
int cl[N];
int dfss(int u,int fa){
	if(vis[u])return 0;
	int mn=1e9;
	for(auto v:g[u]){
		if(v==fa)continue;
		mn=min(mn,dfss(v,u)+1);
	}
	return mn;
}
void check(){
	int daan=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		daan=max(daan,dfss(i,-1));
	}
	ans=min(ans,daan);
}
void tian(int u,int fa,int col){
	cl[u]=col;
	for(auto v:g[u]){
		if(v==fa||!vis[v])continue;
		tian(v,u,col);
	}
}
bool he(){
	memset(cl,0,sizeof(cl));
	int nowc=0; 
	for(int i=1;i<=n;i++){
		if(vis[i]&&!cl[i])tian(i,-1,++nowc);
	}
	return nowc<=2;
}
void dfs(int now,int k){
	if(now>n){
		if(he())check();
		return;
	}
	if(n-now+1<k)return;
	for(int i=now;i<=n;i++){
		vis[i]=1;
		dfs(i+1,k-1);
		vis[i]=0;
	}
}
void work(){
	cin>>n>>k;
	ans=1e9;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	memset(vis,0,sizeof(vis));
	dfs(1,k);
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		work();
	}
	return 0;
}
/*



0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
