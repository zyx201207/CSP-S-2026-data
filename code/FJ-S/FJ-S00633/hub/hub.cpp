#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i=n;i<=m;i++)
//#define int long long
const int N=1e6+10;
int c,t,n,k,u,v,yes[N],ans,z[N],dis[101][101];
struct node{
	int fr,to;
}bri[N];
vector<int>g[N];
int find(int a){
	if(z[a]==a)return a;
	z[a]=find(z[a]);
	return z[a];
}
void merge(int a,int b){
	if(find(a)!=find(b))z[find(a)]=find(b);
}
bool check1(){
	rep(i,1,n)z[i]=i;
	rep(i,1,n-1){
		if(yes[bri[i].fr]&&yes[bri[i].to]){
			merge(bri[i].fr,bri[i].to);
		}
	}
	int mark=0;
	rep(i,1,n){
		if(z[i]==i&&yes[i]){
			mark++;
		}
	}
	return mark<=2;
}
int check2(){
	int maxn=0;
	rep(i,1,n){
		if(yes[i])continue;
		int ans=2e6+10;
		rep(j,1,n){
			if(!yes[j])continue;
			ans=min(ans,dis[i][j]);
		}
		maxn=max(maxn,ans);
	}
	return maxn;
}
void dfs(int now,int use){
	if(now==n+1){
		if(check1())ans=min(ans,check2());
		return;
	}
		dfs(now+1,use);
		if(use>=k)return;
		yes[now+1]=1;
		dfs(now+1,use+1);
		yes[now+1]=0;
}
void dfs2(int root,int now,int fa,int dep){
	dis[root][now]=dep;
	for(int i=1;i<=g[now].size();i++){
		int x=g[now][i-1];
		if(x==fa)continue;
		dfs2(root,x,now,dep+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=2e6+1000;
		cin>>n>>k;
		memset(dis,0,sizeof dis);
		rep(i,1,n-1){
			cin>>u>>v;
			bri[i]={u,v};
			g[u].push_back(v);
			g[v].push_back(u);
		}
		rep(i,1,n)dfs2(i,i,0,0);
		dfs(1,0);
		cout<<ans<<'\n';
		rep(i,1,n)g[i].clear();
	}
	return 0;
}
