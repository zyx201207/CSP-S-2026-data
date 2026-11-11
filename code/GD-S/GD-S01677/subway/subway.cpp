#include <bits/stdc++.h>
#define qq first
#define zz second
using namespace std;
using ll=long long;
constexpr int N=5*1e2+10,M=5*1e5+5;
constexpr ll INF=1e18;
struct node{
	int q,z;
	ll v;
};
int c,n,m,d,q,x,y;
ll ans;
vector<ll> w;
vector<node> g;
vector<pair<int,ll> > edge[N];
vector<int> dd[M];
void dfs(int now,int faid){
	int c=0;
	for(auto to:edge[now]){//线路 
		if(c) break;
		int tod=to.qq;//点 链接点 
		ll vd1=to.zz;
		for(int i:dd[tod]){//线路 
			if(c) break;
			for(auto end:edge[i]){
				if(c) break;
				int dao=end.qq;//点 终点
				ll vd2=end.zz;
				if(dao==y){
					for(auto j:g){
						int yi=j.q;
						int er=j.z;
						ll v=j.v;
						if(yi==now && er==i || yi==i && er==now){
							ans+=v;
							ans+=vd1+vd2;
							c=1;
							break;
						}
					}
				}
			}
		}
	}
	return;
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	w.resize(m+1);
	vector<vector<ll> > e(m+1,vector<ll>(n+1,0));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int u;
			ll v;
			cin>>u>>v;
			e[u][i]=v;//第u个点，第i条线路的代价 
			edge[i].push_back({u,v});//第i条路线的点和其价值
			dd[u].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(e[i].size()){
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(e[i][j] && e[i][k]){
						g.push_back({j,k,e[i][j]+e[i][k]});
					}
				}
			}
		}
	}
	while(q--){
		ans=0;
		ll c=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(c) break;
			for(int j=1;j<=edge[i].size();j++){
				if(c) break;
				int fr=edge[i][j].qq;
				for(int k=j+1;k<=edge[i].size();k++){
					int to=edge[i][k].qq;
					if(fr==to){
						ans+=edge[i][j].zz+edge[i][k].zz;
						c=1;
						break;
					}
				}
			}
		}
		if(c) cout<<ans+w[x]+w[y]<<'\n';
		else{
			for(int i=1;i<=n;i++){
				dfs(i,0);//枚举第i条路线 
				if(c) break;
			}
			cout<<ans+w[x]+w[y]<<'\n';
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
