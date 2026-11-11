#include<bits/stdc++.h>
using namespace std;
const int MAXX=5e5+5;
int c,n,m,d,q,k,x,y,a;
long long w[MAXX],t,time1[505][505],ans;
vector<pair<int,long long>> edge[MAXX];
vector<long long> edge2[505];
bool book[505];
void dfs(int r,int u){
	for(auto v : edge2[u]){
		if(!book[v]){
			time1[r][v]=min(time1[r][v],time1[r][u]+time1[u][v]);
			book[v]=1;
			dfs(r,v);
			book[v]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>t;
			edge[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			time1[i][j]=LONG_LONG_MAX;
	for(int i=1;i<=n;++i)
		time1[i][i]=0;
	for(int i=1;i<=m;++i){
		for(auto j : edge[i])
			for(auto k : edge[i]){
				if(j.first!=k.first)
					time1[j.first][k.first]=min(time1[j.first][k.first],j.second+k.second);	
			}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(time1[i][j]!=LONG_LONG_MAX && i!=j)
				edge2[i].push_back(j);
	for(int i=1;i<=n;++i){
		book[i]=1;
		dfs(i,i);
		book[i]=0;
	}
	while(q--){
		cin>>x>>y;
		ans=LONG_LONG_MAX;
		for(auto i : edge[x]){
			for(auto j : edge[y]){
				ans=min(ans,i.second+j.second+time1[i.first][j.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
