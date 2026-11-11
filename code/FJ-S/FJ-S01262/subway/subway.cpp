#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k;
long long w[500005],pd[505];
vector<pair<long,long>>g[505];
vector<pair<long,long>>g1[505];
long long x,y,ans=INT_MAX;
void dfs(int u,int fa,long long cnt);
void dfs1(int u,int fa,long long cnt){
	if(pd[u]==1)return;
	pd[u]=1;
	for(auto f:g1[u]){
		int r=f.first;
		int b=f.second;
		if(r==fa)continue;
		dfs(r,u,cnt+b);
	}
	pd[u]=0;
}
void dfs(int u,int fa,long long cnt){
	for(auto f:g[u]){
		int r=f.first;
		int b=f.second;
		if(r==fa)continue;
		if(r==y){
			ans=min(ans,cnt+b);
			return;
		}
		dfs1(r,u,cnt+b);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
			g[i].push_back({a,t});
			g1[a].push_back({i,t});
		}
	}
	while(q--){
		ans=INT_MAX;
		for(int i=1;i<=n;i++)pd[i]=0;
		cin>>x>>y;
		dfs1(x,-1,0);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
