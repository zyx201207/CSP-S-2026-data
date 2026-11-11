#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+10;
const int M=1e3+10;
ll T,n,m,d,q,wi[M],ki[M];
struct node{
	ll ai,ti;
	bool operator<(const node s)const{
		return ti<s.ti;
	}
};
vector<node> g[20*M];
vector<node> h[20*M];
bool ff[N][M];
ll dp[M][M];
bool vis[M];
void dfs(ll u){
	if(u==0){
		return;
	}
	for(int i=0;i<g[u].size();i++){
		node v=g[u][i];
		for(int j=0;j<h[v.ai].size();j++){
			
			node qq=h[v.ai][j];
			if(vis[qq.ai]){
				continue;
			}
			cout<<u<<endl;
			dp[u][qq.ai]=min(dp[u][j],v.ti+qq.ti);
			dp[qq.ai][u]=dp[u][qq.ai];
			vis[qq.ai]=1;
			dfs(qq.ai);
		} 
	}
}
int main(){
	memset(dp,0x3f,sizeof dp);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&d,&q);
		for(int i=1;i<=m;i++){
			dp[i][i]=wi[i];
			scanf("%lld",&wi[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&ki[i]);
			for(int j=1;j<=ki[i];j++){
				ll kk,dd;
				scanf("%lld%lld",&kk,&dd);
				g[kk].push_back({i,dd});
				h[i].push_back({kk,dd});
				ff[i][kk]=1;
			}
		}
		vis[1]=1;
		dfs(1);
		for(int i=1;i<m;i++){
			for(int j=i+1;j<=m;j++){
				cout<<dp[i][j]<<endl;
			}
		}
		for(int i=1;i<=q;i++){
			ll xr,yr;
			scanf("%lld%lld",&xr,&yr);
			cout<<m<<endl;
			
		} 		
	}
	return 0;
}
