#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=505;
bool vis[M];
int n,m,q,x,y,z,w[N],f[M][M];
long long ans,dis[M][M];
vector<pair<int,int> >e[M],vc[N];
struct node{
	int id;
	long long v;
	bool operator < (const node &x)const{ return v>x.v;}
};
priority_queue<node>qq;
void dj(int st){
	for(int i=1;i<=n;++i){
		vis[i]=0,dis[st][i]=1e18;
	}
	qq.push({st,dis[st][st]=0ll});
	while(!qq.empty()){
		node u=qq.top();
		qq.pop();
		if(vis[u.id]) continue;
		vis[u.id]=1;
		for(auto [v,ww]:e[u.id]){
			if(dis[st][v]>dis[st][u.id]+ww) qq.push({v,dis[st][v]=dis[st][u.id]+ww});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>x>>n>>m>>y>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>x;
		for(int j=1;j<=x;++j){
			cin>>y>>z;
			vc[y].push_back({i,z});
		}
		for(int j=1;j<i;++j){
			f[i][j]=f[j][i]=2e9+2;
		}
	}
	for(int i=1;i<=m;++i){
		if((x=vc[i].size())<2) continue;
		for(int j=0;j<x;++j){
			for(int k=j+1;k<x;++k){
				int u=vc[i][j].first,v=vc[i][k].first;
				f[u][v]=f[v][u]=min(f[u][v],vc[i][j].second+vc[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j){
			if(f[i][j]!=2e9+2) e[i].push_back({j,f[i][j]}),e[j].push_back({i,f[i][j]});
		}
	}
	for(int i=1;i<=n;++i){
		dj(i);
	}
	while(q--){
		cin>>x>>y;
		ans=2e18;
		for(int i=0;i<vc[x].size();++i){
			for(int j=0;j<vc[y].size();++j){
				ans=min(ans,vc[x][i].second+vc[y][j].second+dis[vc[x][i].first][vc[y][j].first]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
