#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	char y=getchar();
	bool fl=0;
	while(!('0'<=y && y<='9')){
		if(y=='-')fl=1;
		y=getchar();
	}
	x=0;
	while('0'<=y && y<='9'){
		x=(x<<3)+(x<<1)+y-'0';
		y=getchar();
	}
	if(fl)x=-x;
}
#define out(x) putchar(x)
void writ(const int &x){
	if(x<10){
		out(x+'0');
		return ;
	}
	writ(x/10);
	out(x%10+'0');
}
void write(const int &x){
	if(x==0)out('0');
	else if(x<0){
		out('-');
		writ(-x);
	}else writ(x);
}
const int N=1e6+5;
int c,t,n,k,u,v,ans;
vector<int>G[N];
bool vis[N];
int dp[N],fa[N];
int dfs1(int u,int fa){
	if(vis[u]){
		return 0;
	}
//	if(dp[u]!=0)return dp[u];
	dp[u]=1e9;
	for(int v:G[u]){
		if(v==fa)continue;
		dp[u]=min(dfs1(v,u)+1,dp[u]);
	}
	return dp[u];
}
int tot,sum;
int f(){
	sum=0;
//	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++)sum=max(dfs1(i,i),sum);
	return sum;
}
int get(int u){
	if(fa[u]==u)return u;
	return fa[u]=get(fa[u]);
}
bool merge(int u,int v){
	u=get(u);
	v=get(v);
	if(u==v)return 0;
	fa[u]=v;
	return 1;
}
bool check(){
	tot=0;
	for(int u=1;u<=n;u++)fa[u]=u,tot+=vis[u];
	if(tot!=k)return 1;
	for(int u=1;u<=n;u++){
		if(!vis[u])continue;
		for(int v:G[u]){
			if(!vis[v])continue;
			if(merge(u,v))tot--;
		}
	}
	return tot>2;
}
void dfs(int id){
	if(id==n+1){
//		cout<<"QAQ";
		if(check())return;
//		cout<<f()<<':';
//		for(int i=1;i<=n;i++)cout<<vis[i]<<' ';
//		cout<<'\n';
		ans=min(ans,f());
		return ;
	}
	vis[id]=0;
	dfs(id+1);
	vis[id]=1;
	dfs(id+1);
}
void solve(){
	read(n);read(k);
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1;i<n;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ans=1e9;
	dfs(1);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(c);read(t);
	while(t--)solve();
	return 0;
}
