#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=500,M=5e5+100;
int c,n,m,d,q,w[M],id[M],dis[N*3];
vector<pair<int,int> > G[N*3];
bool vis[N*3];
void dij(int s){
	priority_queue<pair<int,int> > q;memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);dis[s]=0;q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;vis[u]=1;
		for(auto v:G[u]){
			if(dis[v.first]>dis[u]+v.second){
				dis[v.first]=dis[u]+v.second;q.push({-dis[v.first],v.first});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;int cnt=m;
	for(int i=1;i<=m;i++){
		int w;cin>>w;G[i].push_back({++cnt,w});G[cnt].push_back({i,w});
//		cnt++;f[i][cnt]=w;f[cnt][i]=w;
		id[i]=cnt;
//		cout<<i<<' '<<cnt<<w<<'\n';
	}
	for(int i=1;i<=n;i++){
		int k,a,t;cin>>k;cnt++;
		for(int j=1;j<=k;j++){
			cin>>a>>t;//f[id[a]][cnt]=t,f[cnt][id[a]]=t;
			G[id[a]].push_back({cnt,t});
			G[cnt].push_back({id[a],t});
//			cout<<id[a]<<' '<<cnt<<' '<<t<<'\n';
		}
	}
//	for(int i=1;i<=cnt;i++)f[i][i]=0;
//	for(int k=1;k<=cnt;k++){
//		for(int i=1;i<=cnt;i++){
//			for(int j=1;j<=cnt;j++){
//				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//			}
//		}
//	}
//	cout<<cnt<<'\n';
//	for(int i=1;i<=cnt;i++){ 
//		for(int j=1;j<=cnt;j++)cout<<f[i][j]<<' ';
//		cout<<'\n';
//	}
	while(q--){
		int l,r;cin>>l>>r;dij(l);cout<<dis[r]<<'\n';
//		for(int i=1;i<=cnt;i++)cout<<dis[i]<<' ';cout<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
