#include<bits/stdc++.h>
using namespace std;
int c,t,n,w,cnt,ans,S,T,dis[1010];
vector<int> e[1010];
bool mk[1010],vis[1010];
void dfs(int x){
	vis[x]=1;
	for(int i:e[x])if(!vis[i]&&mk[i])dfs(i);
}
void dfs2(int x,int fa,int w){
	dis[x]=min(dis[x],w);
	for(int i:e[x])if(i!=fa){
		dfs2(i,x,w+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>w;ans=n-1;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=0;i<(1<<n);i++)if(__builtin_popcount(i)==w){
			int res=0;
			for(int j=1;j<=n;j++){
				dis[j]=1e9;
				if((i>>(j-1))&1)mk[j]=1;
				else mk[j]=0;
				vis[j]=0;
			}
			int cnt=0;
			for(int j=1;j<=n;j++)if(mk[j]&&!vis[j]){
				cnt++;
				dfs(j);
			}
			if(cnt<=2){
				for(int j=1;j<=n;j++)if(mk[j])dfs2(j,0,0);
				for(int j=1;j<=n;j++)res=max(res,dis[j]);
				ans=min(ans,res);
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)e[i].clear();
	}









	return 0;
}

/*


不. 超. 过. 两. 个. 连. 通. 块

恰. 好.
k 座城市

k=2

可以二分答案吗



luogu uid 1096384

今天是 xterfusion 发布一周年。

freopen("xterfusion.in","r",stdin); 
freopen("xterfusion.out","w",stdout);


#include<bits/stdc++.h>
using namespace std;
int c,t,n,w,cnt,ans,S,T,dep[1010],mx[1010],f[1010],dis[1010],dis2[1010],ps[1010],siz[1010],dp[1010][1010],dp2[1010];
vector<int> e[1010];
void dfs(int x,int fa){
	f[x]=fa;
	dp[x][0]=0;
	siz[x]=0;
	for(int i:e[x])if(i!=fa){
		dep[i]=dep[x]+1;
		dfs(i,x);
		mx[x]=max(mx[i],mx[x]);
		for(int j=0;j<=siz[x]+siz[i];j++)dp2[j]=1e9;
		for(int j=0;j<=siz[x];j++){
			for(int k=0;k<=siz[i];k++){
				dp2[j+k]=min(dp2[j+k],max(dp[x][j],dp[i][k]));
			}
		}
		for(int j=0;j<=siz[x]+siz[i];j++)dp[x][j]=dp2[j];
	}
	siz[x]++;
	for(int j=siz[x];j>=1;j--)dp[x][j]=dp[x][j-1];
	dp[x][0]=mx[x];
}
void dfs2(int x,int fa){
	ps[++cnt]=x;dis[x]=dis[fa]+1;
	for(int i:e[x])if(i!=S&&i!=T&&i!=fa)dfs2(i,x);
}
void dfs3(int x,int fa){
	dis2[x]=dis2[fa]+1;
	for(int i:e[x])if(i!=S&&i!=T&&i!=fa)dfs3(i,x);
}
int main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>w;ans=n-1;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			dep[i]=0;
			siz[i]=0;
			dfs(i,0);
			for(int j=1;j<=n;j++)if(j!=i){
				for(int k=j+1;k<=n;k++)if(k!=i&&siz[j]+siz[k]>=w){
					S=j,T=k;
					for(int ca=max(1,w-siz[k]+1);ca<=min(siz[j],w);ca++){
						int res=max(dp[j][ca],dp[k][w-ca]);
						if(res>ans)continue;
						cnt=0;
						dis[f[j]]=1;
						dis2[f[k]]=1;
						dfs2(f[j],0);
						dfs3(f[k],0);
						for(int _=1;_<=cnt;_++)res=max(res,min(dis[ps[_]],dis2[ps[_]]));
						ans=min(ans,res);
					}
				}
			} 
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}









	return 0;
}



*/








