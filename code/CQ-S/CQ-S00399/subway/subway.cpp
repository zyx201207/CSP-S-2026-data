#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int a[500005],t[500005];
int dist[505][505];
vector<pair<int,int>>g[500005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof(dist));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i=-~i)cin>>w[i];
	int k;
	for(int j=1;j<=n;j=-~j){
		cin>>k;
		for(int i=1;i<=k;i=-~i){
			cin>>a[i]>>t[i];
			for(auto it:g[a[i]]){
				dist[it.first][j]=dist[j][it.first]=min(dist[it.first][j],it.second+t[i]);
			}
			g[a[i]].push_back({j,t[i]});
		}
	}
	for(int k=1;k<=n;k=-~k){
		for(int i=1;i<=n;i=-~i){
			for(int j=1;j<=n;j=-~j){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i=-~i)dist[i][i]=0;
	int u,v;
	while(q--){
		int ans=LLONG_MAX;
		cin>>u>>v;
		for(auto it1:g[u]){
			for(auto it2:g[v]){
				ans=min(ans,dist[it1.first][it2.first]+it1.second+it2.second);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
/*
rp++
*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
