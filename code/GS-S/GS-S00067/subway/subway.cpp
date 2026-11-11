#include<bits/stdc++.h>
#define int long long
#define inf (int)1e18
using namespace std;
const int mm=500005,mn=505;
struct Edge{
	int v,w;
	bool operator<(const Edge&o)const{
		return w<o.w;
	}
};
int c,n,m,d,q,w[mm];
int minW[505][505];
vector<Edge>gr[mm+mn];
int dfs(int u,int v,vector<bool>&vst){
	if(vst[u])return inf;
	if(u==v)return 0;
	if(u<505&&v<505&&minW[u][v]!=0&&minW[u][v]!=inf)return minW[u][v];
	int res=inf;
	for(Edge&k:gr[u]){
		vst[u]=1;
		res=min(res,dfs(k.v,v,vst)+k.w);
		vst[u]=0;
	}
	return res;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c>=7&&c<=11){
		for(int i=1;i<505;i++)for(int j=1;j<505;j++)if(i^j)minW[i][j]=inf;
		for(int dots,i=1;i<=n;i++){
			cin>>dots;
			if(dots==1)continue;
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			gr[a].push_back({c,b+d});
			gr[c].push_back({a,b+d});
		}
		for(int i=1;i<mm+mn;i++)sort(gr[i].begin(),gr[i].end());
		for(int u,v;q--;){
			cin>>u>>v;
			vector<bool>vst(mm+mn,0);
			minW[u][v]=dfs(u,v,vst);
			cout<<w[u]+w[v]+minW[u][v]<<'\n';
		}
	}else{
		for(int dots,i=1;i<=n;i++){
			cin>>dots;
			for(int a,b,j=1;j<=dots;j++){
				cin>>a>>b;
				gr[i+mm].push_back({a,b});
				gr[a].push_back({i+mm,b});
			}
		}
		for(int i=1;i<mm+mn;i++)sort(gr[i].begin(),gr[i].end());
		for(int u,v;q--;){
			vector<bool>vst(mm+mn,0);
			cin>>u>>v;
			cout<<w[u]+w[v]+dfs(u,v,vst)<<'\n';
		}
	}
	return 0;
}
