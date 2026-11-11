#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<pair<int,int>> g[N];
long long w[N],t[505][N],dis[N],a[505][N];
int k[505];
int c,n,m,d,h;

void dfs(int u,int v){//mlog(n);
	memset(dis,127,sizeof(dis));
	set<pair<int,int>> q;
	dis[u]=0;
	for(int i=1;i<=m;i++){
		q.insert({dis[i],i});
	}
	while(q.size()){
		int x=q.begin()->second;
		q.erase(q.begin());
//		cout<<x<<"\n";
		for(auto p:g[x]){
			int y=p.first,b=p.second;
			if(dis[x]+t[b][x]+t[b][y]<dis[y]){
				q.erase({dis[y],y});
				dis[y]=dis[x]+t[b][x]+t[b][y];
				q.insert({dis[y],y});
//				cout<<x<<" "<<y<<"\n";
			}
		}
	}
	long long ans=dis[v]+w[u]+w[v];
	cout<<ans<<"\n";
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>h;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){//nk^2
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			int x=a[i][j];
			cin>>t[i][x];
		}
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<j;l++){
				int x=a[i][j],y=a[i][l];
				g[x].push_back({y,i});
				g[y].push_back({x,i});
			}
		}
	}
	while(h--){//q
		int x,y;
		cin>>x>>y;
		dfs(x,y);
	}
	return 0;
}
