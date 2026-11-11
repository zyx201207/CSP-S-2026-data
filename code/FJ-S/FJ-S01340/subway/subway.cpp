#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505,maxm=5e5+5;
int n,m,d,qry;
int wt[maxm],k[maxn];
vector<pair<int,int>> g[maxn],h[maxm];
bool flg[maxm],flg2[maxn];
int dis2[maxn][maxn],dis[maxm];
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
void func(int x){
	for(int i=1;i<=m;i++){
		dis[i]=1e18,flg[i]=0;
	}
	for(int i=1;i<=n;i++){
		dis2[x][i]=1e18,flg2[i]=0;
	}
	dis2[x][x]=0;
	q.push({0,{0,x}});
	while(!q.empty()){
		int ds=q.top().first,op=q.top().second.first,u=q.top().second.second;
		q.pop();
		if(op){
			if(flg[u]){
				continue;
			}
			flg[u]=1;
			for(auto e:h[u]){
				int v=e.first,w=e.second;
				if(dis2[x][v]>ds+w){
					dis2[x][v]=ds+w;
					q.push({dis2[x][v],{0,v}});
				}
			}
		}else{
			if(flg2[u]){
				continue;
			}
			flg2[u]=1;
			for(auto e:g[u]){
				int v=e.first,w=e.second;
				if(dis[v]>ds+w){
					dis[v]=ds+w;
					q.push({dis[v],{1,v}});
				}
			}
		}
	}
}
void solve(){
	int c;
	cin>>c;
	cin>>n>>m>>d>>qry;
	for(int i=1;i<=m;i++){
		cin>>wt[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,v;
			cin>>u>>v;
			g[i].push_back({u,v});
			h[u].push_back({i,v});
		}
	}
	for(int i=1;i<=n;i++){
		func(i);
	}
	while(qry--){
		int ans=1e18;
		int u,v;
		cin>>u>>v;
		for(auto e:h[u]){
			int i=e.first,w=e.second;
			for(auto f:h[v]){
				int j=f.first,z=f.second;
				ans=min(ans,dis2[i][j]+w+z);
			}
		}
		cout<<ans+wt[u]+wt[v]<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
