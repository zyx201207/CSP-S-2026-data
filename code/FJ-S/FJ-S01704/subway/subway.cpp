#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<bitset>
using namespace std;

typedef long long ll; 
const int maxn=505,maxm=500005;
struct edge{
	int to,id;
};
int c,n,m,d,q;
int w[maxm],a[maxm],k[maxm][25],tot[maxm];//k是记录每个站点经过的每一条line，tot是每一个站经过的线路数 
int t[maxm][maxn];//t是每个站厅到每个站台的时间 
vector<edge> G[maxm];
bitset<maxm> vis;

ll dfs(int u,int id,int goal){
	if(u==goal){
		return (ll)t[u][id];
	}
	vis[u]=1;
	ll ans=1e18;
	for(int i=0,v,iid;i<(int)G[u].size();i++){
		v=G[u][i].to; iid=G[u][i].id;
		if(vis[v]) continue;
		if(iid==id){
			ans=min(ans,dfs(v,id,goal));
		}
		else{
			ans=min(ans,(ll)t[u][id]+(ll)t[u][iid]+dfs(v,iid,goal));
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,kk;i<=n;i++){
		cin>>kk;
		for(int j=1;j<=kk;j++){
			cin>>a[j]>>t[a[j]][i];
			k[a[j]][++tot[a[j]]]=i;
		}
		for(int j=1;j<kk;j++){
			for(int z=j+1;z<=kk;z++){
				G[a[j]].push_back(edge({a[z],i}));
				G[a[z]].push_back(edge({a[j],i}));
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		vis.reset();
		ll ans=1e18;
		for(int i=1;i<=tot[x];i++){
			ans=min(ans,t[x][k[x][i]]+dfs(x,k[x][i],y));
		}
		ans+=(w[x]+w[y]);
		cout<<ans<<"\n";
	}
	
	return 0;
}
//17:00瞎写了一无法保证正确性的解法  byd
//为什么要多组数据？多组数据是错的！！！ 
