#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,k,d[1000010],lrt,rrt,lc,rc,lans,rans,miku;
int maxn[1000010],smaxn[1000010],vis[1000010],sum[5][1000010];
struct ab{
	int b,use,nxt;
}e[2000010];
void cun(int a,int b){
	e[++k].b=b;
	e[k].nxt=d[a];
	e[k].use=0;
	d[a]=k;
}
void dfs(int u,int fa){
	for(int i=d[u];i;i=e[i].nxt){
		int v=e[i].b;
		if(v==fa||e[i].use)continue;
		dfs(v,u);
		if(maxn[v]+1>maxn[u]){
			smaxn[u]=maxn[u];
			maxn[u]=maxn[v]+1;
		}
		else smaxn[u]=max(smaxn[u],maxn[v]+1);
	}
}
void change(int u,int fa,int fst){
	vis[u]=fst;
	if(u!=fst){
		if(maxn[u]+1==maxn[fa]){
			if(smaxn[fa]+1>maxn[u]){
				smaxn[u]=maxn[u];
				maxn[u]=smaxn[fa]+1;
			}
			else smaxn[u]=max(smaxn[u],smaxn[fa]+1);
		}
		else if(maxn[fa]+1>maxn[u]){
			smaxn[u]=maxn[u];
			maxn[u]=maxn[fa]+1;
		}
		else smaxn[u]=max(smaxn[u],maxn[fa]+1);
	}
	for(int i=d[u];i;i=e[i].nxt){
		int v=e[i].b;
		if(v==fa||e[i].use)continue;
		change(v,u,fst);
	}
}
void get_ans(int u,int fa,int s){
	for(int i=d[u];i;i=e[i].nxt){
		int v=e[i].b;
		if(v==fa||e[i].use)continue;
		get_ans(v,u,s);
		maxn[u]=max(maxn[u],maxn[v]+1);
	}
	sum[s][maxn[u]]++;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			d[i]=0;maxn[i]=0;smaxn[i]=0;vis[i]=0;
			sum[1][i]=0;sum[2][i]=0;
		}
		k=1;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			cun(u,v);
			cun(v,u);
		}
		dfs(1,0);
		change(1,0,1);
		maxn[0]=n+1;maxn[n+1]=0;
		for(int i=1;i<=n;i++){
			if(maxn[i]<maxn[lrt])lrt=i;
		}
		for(int i=1;i<=n;i++){
			maxn[i]=0;
		}
		get_ans(lrt,0,1);
		miku=n;
		for(int i=n-1;i>=0;i--){
			sum[1][i]+=sum[1][i+1];
			if(sum[1][i]<=m)miku=i;
			else break;
		}
		for(int p=2;p<=k;p+=2){
			e[p].use=1;e[p^1].use=1;
			for(int i=1;i<=n;i++){
				sum[1][i]=0;sum[2][i]=0;maxn[i]=0;smaxn[i]=0;vis[i]=0;
			}
			lrt=e[p].b;rrt=e[p^1].b;
			dfs(lrt,0);
			change(lrt,0,lrt);
			dfs(rrt,0);
			change(rrt,0,rrt);
			lc=0;rc=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==lrt&&maxn[i]<maxn[lc])lc=i;
				if(vis[i]==rrt&&maxn[i]<maxn[rc])rc=i;
			}
			for(int i=1;i<=n;i++){
				maxn[i]=0;
			}
			get_ans(lc,0,1);
			get_ans(rc,0,2);
			int num=m;lans=n;rans=n;
			for(int i=n-1;i>=0;i--){
				sum[1][i]+=sum[1][i+1];
				sum[2][i]+=sum[2][i+1];
				if(sum[2][i]<=m)rans=i;
			}
			for(int l=1,r=m-1;l<=m-1;l++,r--){
				while(sum[1][lans-1]<=l)lans--;
				while(sum[2][rans]>r)rans++;
				miku=min(miku,max(lans,rans));
			}
			e[p].use=0;e[p^1].use=0;
		}
		cout<<miku<<"\n";
	}
	return 0;
}
