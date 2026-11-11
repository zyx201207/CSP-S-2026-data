#include<bits/stdc++.h> 
#define int long long 
using namespace std;
const int inf=1e16;
int c,n,m,d,q,dis[505][505],w[500005],k[505];
vector<pair<int,int>> g[500005];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int v,w;
		    cin>>v>>w;
			g[v].emplace_back(i,w);
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:g[i]) {
			for(auto y:g[i]){
				if(x==y) continue;
				dis[x.first][y.first]=dis[y.first][x.first]=x.second+y.second;
			}
		}
	}
	floyd();
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	for(int i=1;i<=q;i++){
		int ans=inf,x,y;
		cin>>x>>y;
		for(auto a:g[x]){
			for(auto b:g[y]){
				ans=min(ans,a.second+b.second+dis[a.first][b.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
