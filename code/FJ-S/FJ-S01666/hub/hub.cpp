#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5,N2=4002;
ll c,T,n,k,dp[N],sum,dp2[N],dis[N2][N2],siz[N],maxd[N],maxd2[N];
ll dfn[N],cnt,fa[N],dep[N];
vector<ll> G[N];
bool flag[N2][N2];
void dfs0(int u,int fa2,int rt){
	for(auto v:G[u]){
		if(v==fa2)continue;
		dis[rt][v]=dis[rt][u]+1;
		dfs0(v,u,rt);
	}
}
void dfs(int u,int d){
	siz[u]=1;
	maxd[u]=0;
	dp[u]=1;
	dep[u]=dep[fa[u]]+1;
	dfn[u]=++cnt;
	for(auto v:G[u]){
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v,d);
		if(maxd[v]+1>d)dp[u]+=dp[v];
		maxd[u]=max(maxd[u],maxd[v]+1);
		siz[u]+=siz[v];
	}
//	cout <<u<<" "<<dp[u]<<"\n";
}
void dfs2(int u,int d){
	maxd2[u]=0;
	if(fa[u]){
		dp2[u]=1;
		for(auto v:G[fa[u]]){
			if(v==u||v==fa[fa[u]])continue;
			if(maxd[v]+1>d)dp2[u]+=dp[v];
			maxd2[u]=max(maxd2[u],maxd[v]+1);
		}
		if(maxd2[fa[u]]+1>d)dp2[u]+=dp2[fa[u]];
		maxd2[u]=max(maxd2[u],maxd2[fa[u]]+1);
//		cout <<u<<" "<<dp2[u]<<"\n";
	}
	for(auto v:G[u]){
		if(v==fa[u])continue;
		dfs2(v,d);
	}
}
//void dfs3(int u,int d,int rt){
//	maxd3[u]=0;
//	for(auto v:G[u]){
//		if(v==fa2[u])continue;
//		fa2[v]=u;
//		dfs3(v,d,rt);
//		maxd3[u]=max(maxd3[u],maxd3[v]+1);
//	}
//}
//void dfs4(int u,int d,int rt){
//	maxd4[u]=0;
//	if(fa2[u]!=rt){
//		for(auto v:G[fa2[u]]){
//			if(v==u||v==fa2[fa2[u]])continue;
//			maxd4[u]=max(maxd4[u],maxd3[v]+1);
//		}
//		maxd4[u]=max(maxd4[u],maxd4[fa2[u]]+1);
//		if(maxd4[u]+1<=d)flag[rt][u]=1;
//	}else flag[rt][u]=1;
//	for(auto v:G[u]){
//		if(v==fa2[u])continue;
//		dfs4(v,d,rt);
//	}
//}
bool insub(int u,int v){
	return dfn[u]<=dfn[v]&&dfn[v]+siz[v]<=dfn[u]+siz[u];
}
bool check(ll x){
	cnt=0; 
	dfs(1,x);
	dfs2(1,x);
//	cout <<x<<"\n";
//	for(int i=2;i<=n;i++){
//		for(int j=1;j<=n;j++)maxd3[j]=maxd4[j]=flag[i][j]=0;
//		fa2[fa[i]]=i;
//		dfs3(fa[i],x,i);
//		dfs4(fa[i],x,i);
//		for(int j=1;j<=n;j++){
//			cout <<flag[i][j]<<" ";
//		}
//		cout <<"\n";
//	}
	for(int i=1;i<=n;i++){
		if(maxd2[i]+1<=x&&siz[i]>=k&&dp[i]<=k)return 1;
		if(i==1)continue;
		for(int j=i;j<=n;j++){
			int u=i,v=j;
			if(dep[u]>dep[v])swap(u,v);
			bool f2=1;
			if(insub(u,v)){
				for(int k=1;k<=n;k++){
					if(insub(v,k))continue;
					if(!insub(u,k))continue;
					if(min(dis[fa[u]][k],dis[v][k])>x){
						f2=0;
						break;
					}
				}
				if(dp[v]+dp2[u]<=k&&f2){
//					cout <<u<<" "<<v<<"\n";
					return 1;
				}
			}else{
				for(int k=1;k<=n;k++){
					if(insub(v,k))continue;
					if(insub(u,k))continue;
					if(min(dis[u][k],dis[v][k])>x){
						f2=0;
						break;
					}
				}
				if(dp[u]+dp[v]<=k&&f2){
//					cout <<u<<" "<<v<<"\n";
					return 1;
				}
			}
		}
	}
	return 0;
}
void solve(){
	cin >>n>>k;
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin >>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		dfs0(i,0,i);
	}
	int l=0,r=n-1,ans=n-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout <<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>c>>T;
	while(T--)solve();
}
